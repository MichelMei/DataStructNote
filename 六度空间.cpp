#include <iostream>
#include <queue>
#include <iomanip>
#include <string.h>
using namespace std;

//ͨ������N���ڵ㣬M���ߣ�M�ĸ�ʽ�������ڵ��ţ�
//���ж�ÿһ���ڵ�ͨ�������߿���ͨ�Ľڵ�����ռ�ܱ����İٷ�֮���٣������ʽҪ��С�������λ
//���ģ��Ƚ����ڽӱ�������BFS�㷨
//��Ҫʵ�ֵĹ��ܣ������ṹ�����飩 ����� DFS����һ��counter������ ���

#define MaxNum 1050

int N = 0, M = 0;
int Visted[MaxNum];

typedef struct AdjVNode* PtrToAdjVNode;
struct GNode
{
	PtrToAdjVNode FirstNode;
}G[MaxNum];

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	PtrToAdjVNode Next;
	int AdjV;//�ڽӵ��±�
};

void BuildG()
{
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
	{
		G[i].FirstNode = NULL;
	}
}
void Insert()
{
	int V1, V2;
	for (int i = 0; i < M; i++)
	{
		cin >> V1 >> V2;//�����һ�ͱ߶�
		PtrToAdjVNode NewNode;
		NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
		NewNode->Next = G[V1].FirstNode;
		G[V1].FirstNode = NewNode;
		NewNode->AdjV = V2;
		//����ͼ
		NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
		NewNode->Next = G[V2].FirstNode;
		G[V2].FirstNode = NewNode;
		NewNode->AdjV = V1;
	}
}

double BFS(int i)
{
	int counter = 1;
	int V = i;
	int level = 0;
	int last = i;
	int tail = 0;
	Visted[i] = 1;
	PtrToAdjVNode VNode;
	queue<int>Q;
	Q.push(i);
	while (!Q.empty())
	{
		V = Q.front();
		Q.pop();
		VNode = G[V].FirstNode;
		while (VNode != NULL)
		{
			if (Visted[VNode->AdjV] != 1)
			{
				Visted[VNode->AdjV] = 1;
				Q.push(VNode->AdjV);
				counter++;
				tail = VNode->AdjV;
			}
			VNode = VNode->Next;
		}
		if (last == V)
		{
			level++;
			last = tail;
		}
		if (level == 6)
		{
			break;
		}
	}
	return counter;
}


int main()
{
	double counter = 0;
	BuildG();
	Insert();
	memset(Visted, 0, N);
	for (int i = 1; i <= N; i++)//�˴�ѭ������DFS�㷨
	{
		for (int i = 1; i <= N; i++)
		{
			Visted[i] = 0;
		}
		counter = BFS(i);
		cout << i << ": " << setiosflags(ios::fixed) << setprecision(2) << counter / N * 100 << "%" << endl;
	}
	system("pause");
	return 0;
}