/*
	input:
	5
	10 6 2 3 -1
	output:
	10 6 2 3 -1
	Nộp code trên ELSE: hàm endList(), insertList() và readList()
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

void makenullList(List* pL) {
	(*pL) = (struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next = NULL;
}

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

void readList(List* pL) {
	makenullList(pL);
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		insertList(x, endList(*pL), pL);
	}
}

int main() {
	List L;
	Position p;
	readList(&L);

	p = L;
	while (p->Next != NULL)
	{
		printf("%d ", p->Next->Element);
		p = p->Next;
	}
	return 0;
}