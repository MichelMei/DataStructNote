#include<iostream>
using namespace std;

typedef struct PolyNode* Polynomial;
struct PolyNode
{
	int coef;//ϵ��
	int expon;//ָ��
	Polynomial Link;//����ڵ�
};

void Attach(int c, int e, Polynomial* pRear);
void PrintPoly(Polynomial P);

Polynomial ReadPoly()//�������ʽ
{
	Polynomial P, t, Rear;
	int c, e, N;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->Link = NULL;//�˴�����һ���ս�㣬ʹRear���ڿս��
	Rear = P;
	cout << "����������" << endl;
	cin >> N;
	cout << "������ϵ����ָ��" << endl;
	while (N--)
	{
		cin >> c >> e;
		Attach(c, e, &Rear);
	}
	t = P;//������ɾ���ս��
	P = P->Link;
	free(t);
	return P;
}
void Attach(int c, int e, Polynomial* pRear)//���һ����ָ��ָ���ָ��, ��Ϊ���ݵ��β�
{                                          
	Polynomial P;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->coef = c;
	P->expon = e;
	P->Link = NULL;
	(*pRear)->Link = P;//�˴�*��������ã�������Rearָ�롣ʹ��P������ԭ����Rear����
	*pRear = P;//��β��������Ϊ�µ�P
}
Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial P, t1, t2, Rear, t;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->Link = NULL;
	Rear = P;
	t1 = P1;
	t2 = P2;
	while (t1 && t2)
	{
		if (t1->expon == t2->expon)
		{
			if (t1->coef + t2->coef)
			{
				Attach(t1->coef + t2->coef, t1->expon, &Rear);
				t1 = t1->Link;
				t2 = t2->Link;
			}
			else
			{
				//�˴���ȡ��ֱ�����ķ�ʽ
				t1 = t1->Link;
				t2 = t2->Link;
			}
		}
		else if (t1->expon > t2->expon)
		{
			Attach(t1->coef, t1->expon, &Rear);
			t1 = t1->Link;
		}
		else
		{
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->Link;
		}
	}
	while (t1)
	{
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->Link;
	}
	while (t2)
	{
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->Link;
	}
	t = P;
	P = P->Link;
	free(t);
	return P;
}
Polynomial Mult1(Polynomial P1, Polynomial P2)//������뷨
{
	Polynomial t1, t2, t, Rear, P;
	int c, e;
	if (!P1 || !P2)
	{
		return NULL;
	}
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->Link = NULL;
	Rear = P;
	while (t2)
	{
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->Link;//����t1�ĵ�һ�����t2��ÿһ��
	}
	t1 = t1->Link;
	while (t1)
	{
		t2 = P2;
		Rear = P;
		while (t2)
		{
			c = t1->coef * t2->coef;
			e = t1->expon + t2->expon;
			while (Rear->Link && Rear->Link->expon > e)
			{
				Rear = Rear->Link;
			}
			if (Rear->Link && Rear->Link->expon == e)
			{
				if (Rear->Link->coef + c)
				{
					Rear->Link->coef += c;
				}
				else
				{
					t = Rear->Link;
					Rear->Link = t->Link;
					free(t);
				}
			}
			else
			{
				t = (Polynomial)malloc(sizeof(PolyNode));
				t->coef = c;
				t->expon = e;
				t->Link = Rear->Link;
				Rear->Link = t;
				Rear = Rear->Link;
			}
			t2 = t2->Link;
		}
		t1 = t1->Link;
	}
	t2 = P;
	P = P->Link;
	free(t2);
	return P;
}
Polynomial Mult2(Polynomial P1, Polynomial P2)
{
	Polynomial t1, t2, t, Rear, PS, P;
	int flag = 0;
	if (!P1 || !P2)
	{
		return NULL;
	}
	t1 = P1;
	t2 = P2;
	PS = (Polynomial)malloc(sizeof(PolyNode));

	while (t1)
	{
		P = (Polynomial)malloc(sizeof(PolyNode));
		P->Link = NULL;
		Rear = P;
		t2 = P2;
		while (t2)
		{
			if (t1->expon + t2->expon)//ָ����Ӳ�Ϊ0ʱִ�У��������Ϊ0��ʱ��δ������
			{
				Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
			}
			t2 = t2->Link;
		}
		t1 = t1->Link;
		t = P;
		P = P->Link;
		free(t);
		if (!flag)
		{
			PS = P;
			flag = 1;
		}
		else
		{
			PS = Add(PS, P);
		}
	}
	return PS;
}
void PrintPoly(Polynomial P)
{
	int flag = 0;//������ʽ
	if (!P)
	{
		cout << "����ʽΪ��" << endl;
	}
	while (P)
	{
		if (!flag)
			flag = 1;
		else
			cout << "  " ;
		cout << P->coef << " " << P->expon;
		P = P->Link;
	}
	cout << endl;
}
int main()
{
	Polynomial P1, P2, PP1, PP2, SP;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP1 = Mult1(P1, P2);
	PP2 = Mult2(P1, P2);
	SP = Add(P1, P2);
	PrintPoly(PP1);
	PrintPoly(PP2);
	system("pause");
	return 0;
}
//���������⣺��ָ����˵���0ʱ����δ����
//���������⣺�ӷ���������һ��Ϊ��ʱ���޷�����ִ��