#include <iostream>
using namespace std;

#define MaxVertex 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode* PtrToENode;
typedef PtrToENode Edge;
struct ENode
{
	Vertex V1, V2;//�����V1��V2��
	WeightType Weight;
};

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	Vertex AdjV;//�ڽӵ��±�
	WeightType Weight;
	PtrToAdjVNode Next;//ָ����һ���ڽӵ㣬����ĸо���������
};

typedef struct Vnode
{
	PtrToAdjVNode FirstEdge;//��ͷָ��
	DataType Data;
}AdjList[MaxVertex];

typedef struct GNode* PtrToGNode;
typedef PtrToGNode LGraph;
struct GNode
{
	int Nv;
	int Ne;
	AdjList G;
};

LGraph CreatGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++)
	{
		Graph->G[V].FirstEdge = NULL;
	}
	return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	cin >> Nv;
	Graph = CreatGraph(Nv);
	cin >> Graph->Ne;
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++)
		{
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(Graph, E);
		}
	}
	for (V = 0; V < Graph->Nv; V++)
	{
		cin >> Graph->G[V].Data;
	}
	return Graph;
}


int main()
{


	system("pause");
	return 0;
}