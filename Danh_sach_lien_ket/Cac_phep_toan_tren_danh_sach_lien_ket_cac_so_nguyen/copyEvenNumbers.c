/*
	output:
	2 2
	Nộp code trên ELSE: first(), endList(), next(), retrieve() và copyEvenNumbers
*/

#pragma warning(disable:4996)

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

Position first(List L) {
	return L;
}

Position endList(List L) {
	Position P = L;
	while (P->Next != NULL) {
		P = P->Next;
	}
	return P;
}

Position next(Position P, List L) {
	return P->Next;
}

ElementType retrieve(Position P, List L) {
	return P->Next->Element;
}

void insertList(ElementType x, Position P, List* pL) {
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}

void append(int x, List* pL)
{
	insertList(x, endList(*pL), pL);
}

void copyEvenNumbers(List L1, List* pL2)
{
	makenullList(pL2);
	Position P = first(L1), E = endList(L1);
	while (P != E)
	{
		if (retrieve(P, L1) % 2 == 0)
			append(retrieve(P, L1), pL2);
		P = next(P, L1);
	}
}

int main() {
	List L1, L2;
	Position p;

	makenullList(&L1);
	append(2, &L1);
	append(21, &L1);
	append(2, &L1);

	copyEvenNumbers(L1, &L2);

	p = L2;
	while (p->Next != NULL)
	{
		printf("%d ", p->Next->Element);
		p = p->Next;
	}
	return 0;
}