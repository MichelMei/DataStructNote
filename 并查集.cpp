#include <iostream>
using namespace std;

int f[20] = {0}, n, m, sum = 0;
void intt()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		f[i] = i;
	}
}

int getf(int v)
{
	if (f[v] == v)
	{
		return v;
	}

	else
	{
		f[v] = getf(f[v]);//�˴�Ϊ·��ѹ��
		return f[v];//�����˵ݹ��˼��
	}
}

void merge(int v, int u)
{
	int t1, t2;//t1��t2�������ɸ��ڵ�
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2)
	{
		f[t2] = t1;
	}
}

int main()
{
	int i, x, y;
	//x,y��������������ص�Ԫ��
	//nΪ������
	//mΪһ���ж�������ص���Ϣ
	cin >> n >> m;
	intt();
	for (i = 1; i <= m; i++)
	{
		cin >> x >> y;
		merge(x, y);
	}
	for (i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			sum++;
		}
	}
	cout << sum << endl;

	system("pause");
	return 0;
}