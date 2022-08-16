#include <iostream>
#include <stack>
using namespace std;

//�������������װ�������װ����ջ��������ʧ��
//�����������

void Judeg(int Capacity, int N, int M)
{
	int Data;
	int cmp = 0;

	stack <int> S;
	for (int i = 0; i < N; i++)
	{
		int Maxnum = 0;
		int flag = 1;
		for (int j = 1; j <= M; j++)
		{
			cin >> Data;
			if (Data > Maxnum)
			{
				for (int k = Maxnum + 1; k <= Data; k++)
				{
					S.push(k);
				}
				cmp = S.top();
				if (Data != cmp)
				{
					flag = 0;
				}
				if (S.size() > Capacity)
				{
					flag = 0;
				}
				S.pop();
				Maxnum = Data;
			}
			if (Data < Maxnum)
			{
				if (!S.empty())
				{
					cmp = S.top();
					S.pop();
				}
				if (Data != cmp)
				{
					flag = 0;
				}
			}
		}
		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		while (!S.empty())
		{
			S.pop();
		}
	}
}

int main()
{
	int Capacity;//��ջ������
	int N;//��Ҫ���N������
	int M;//һ������M������
	cin >> Capacity >> M >> N;
	Judeg(Capacity, N, M);
	system("pause");
	return 0;
}