#include <iostream>
#include <queue>
using namespace std;

#define MaxSize 10
typedef int Tree;
typedef int ElementType;
int N;

struct BinTree
{
	ElementType Data;
	Tree Left;
	Tree Right;
}T[MaxSize];

Tree BuildTree()
{
	int i;
	int check[MaxSize];
	char l, r;

	cin >> N;
	for ( i = 0; i < N; i++)
	{
		check[i] = 0;
		T[i].Data = i;
	}
	for ( i = 0; i < N; i++)
	{
		cin >> l >> r;
		if (l != '-')
		{
			T[i].Left = l - '0';
			check[T[i].Left] = 1;
		}
		else
		{
			T[i].Left = -1;
		}
		if (r != '-')
		{
			T[i].Right = r - '0';
			check[T[i].Right] = 1;
		}
		else
		{
			T[i].Right = -1;
		}
	}
	for ( i = 0; i < N; i++)
	{
		if (check[i] != 1)
		{
			break;
		}
	}
	return i;//iΪ���ڵ�����
}

void PrintLeaves(int Root)//�ò�������������
{
	int root = Root;
	//int l, r;
	queue <BinTree> Q;
	BinTree t;

	Q.push(T[root]);
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		if (t.Left == -1 && t.Right == -1)//�ж��Ƿ�ΪҶ�ڵ�
		{
			if (!Q.empty())
			{
				cout << t.Data << " ";
			}
			else
			{
				cout << t.Data;
			}
		}
		if (t.Left != -1)
		{
			Q.push(T[t.Left]);
		}
		if (t.Right != -1)
		{
			Q.push(T[t.Right]);
		}
	}
}

int main()
{
	int root = BuildTree();
	PrintLeaves(root);

	system("pause");
	return 0;
}