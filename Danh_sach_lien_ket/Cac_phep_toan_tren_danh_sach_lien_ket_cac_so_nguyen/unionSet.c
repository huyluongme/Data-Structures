/*
	output:
	1 2 3 4 5
	Nộp code trên ELSE:  hàm first(), endList(), next(), retrieve() và unionSet()
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

int emptyList(List L) {
	return L->Next == NULL;
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

void append(ElementType x, List* pL)
{
	insertList(x, endList(*pL), pL);
}

int member(ElementType x, List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == x)
			return 1;
		P = next(P, L);
	}
	return 0;
}

List unionSet(List L1, List L2) {
	List L;
	makenullList(&L);
	Position P = first(L1), E = endList(L1);
	while (P != E) {
		append(retrieve(P, L1), &L);
		P = next(P, L1);
	}
	P = first(L2);
	E = endList(L2);
	while (P != E) {
		if (!member(retrieve(P, L2), L1))
			append(retrieve(P, L2), &L);
		P = next(P, L2);
	}
	return L;
}

int main() {
	List L1, L2, L;
	int i;

	Position p;
	makenullList(&L1);
	makenullList(&L2);
	for (i = 1; i <= 3; i++)
		append(i, &L1);
	for (i = 2; i <= 5; i++)
		append(i, &L2);
	L = unionSet(L1, L2);
	p = L;
	while (p->Next != NULL)
	{
		printf("%d ", p->Next->Element);
		p = p->Next;
	}
	return 0;
}