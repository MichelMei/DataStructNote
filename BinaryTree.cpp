#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree; /* ���������� */
struct TNode { /* ����㶨�� */
    ElementType Data; /* ������� */
    BinTree Left;     /* ָ�������� */
    BinTree Right;    /* ָ�������� */
};

int main()
{


	system("pause");
	return 0;
}
