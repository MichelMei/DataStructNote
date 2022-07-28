#include <iostream>
using namespace std;

//�����ѵ�ʱ�临�Ӷ�ΪO��N��
//�������ʱ�临�Ӷ�ΪO��NlogN��

int h[100];
int n;//�ѵĴ�С
void swap(int x, int y)
{
	int temp;
	temp = h[x];
	h[x] = h[y];
	h[y] = temp;
}

void siftdownmin(int i)
{
	int t, flag = 0;
	while (i * 2 <= n && flag == 0)//��Ҷ�ڵ������С���ܽڵ���
	{
		if (h[i] > h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		if (i * 2 + 1 <= n)//���������Ƚ�
		{
			if (h[t] > h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}
		if (t != i)
		{
			swap(t, i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}
void siftdownmax(int i)
{
	int t, flag = 0;
	while (i * 2 <= n && flag == 0)//��Ҷ�ڵ������С���ܽڵ���
	{
		if (h[i] < h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		if (i * 2 + 1 <= n)//���������Ƚ�
		{
			if (h[t] < h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}
		if (t != i)
		{
			swap(t, i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}
void creatminheap()//������С��
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		siftdownmin(i);
	}
}
void creatmaxheap()//��������
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		siftdownmax(i);
	}
}
void heapsort()//������ת��Ϊ��С��
{
	while (n > 1)
	{
		swap(1, n);
		n--;
		siftdownmax(1);
	}
}
int deletemax()
{
	int t;
	t = h[1];
	h[1] = h[n];//�������������ŵ���ߴ���
	n--;
	siftdownmin(1);//�Զѵ�˳�����½��е���
	return t;//���ضѵĵ�һ��ֵ�������С����
}
int main()
{
	int i, num;
	cin >> num;
	for (i = 1; i <= num; i++)
	{
		cin >> h[i];
	}
	n = num;
	creatminheap();//����������齨���ɶ�
	for (i = 1; i <= num; i++)
	{
		cout << deletemax() << endl;//��С��������������ʱ�������ֱ��������鼴��
	}

	system("pause");
	return 0;
}