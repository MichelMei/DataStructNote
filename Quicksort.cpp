#include <iostream>
using namespace std;

int a[101], n;
void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
	{
		return;
	}
	temp = a[left];//��׼λ
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		while (a[i] <= temp && i < j)
		{
			i++;
		}
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];//��׼λ��ij������λ�õ���
	a[i] = temp;//�������µĻ�׼λ

	quicksort(left, i - 1);//����һ����׼λ������ȷλ�ú����õݹ�˼�봦����ȷλ����ߵ�����
	quicksort(i + 1, right);//�����ұߵ�����
}

int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	quicksort(1, n);
	for (i = 1; i < n; i++)
	{
		cout << a[i];
	}
	system("pause");
	return 0;
}
//����˼·
//�����ұ������Ȼ�׼λС��������߱Ȼ�׼λ�����
//ƽ�����Ӷ�ΪNlogN����ӵ������ΪN^2