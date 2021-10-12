/*
	output:
	1 5 10 -10
	Nộp code trên ELSE: hàm endList(), insertList() và append()
*/
#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

struct Node {
	ElementType Element;
	struct Node* Next;
};

typedef struct Node* Position;
typedef Position List;

Position endList(List L) {
	Position P = L;
	while (P->Next != NULL) {
		P = P->Next;
	}
	return P;
}

void insertList(ElementType x, Position P, List* pL) {
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}

void append(ElementType x, List* pL)
{
	insertList(x, endList(*pL), pL);
}

int main()
{
	List L;
	Position p;
	L = (struct Node*)malloc(sizeof(struct Node));
	L->Next = NULL;

	append(1, &L);
	append(5, &L);
	append(10, &L);
	append(-10, &L);
	p = L;
	while (p->Next != NULL)
	{
		printf("%d ", p->Next->Element);
		p = p->Next;
	}
	printf("\n");
	return 0;
}