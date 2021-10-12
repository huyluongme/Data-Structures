/*
	output:
	2 4 6 8 10
	Nộp code trên ELSE: hàm firs(), endList(), next(), retrieve(), deleteList() và sort()
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

void deleteList(Position P, List* pL) {
	if (next(P, *pL) != NULL) {
		Position tmp = P->Next;
		P->Next = tmp->Next;
		free(tmp);
	}
}

void sort(List* pL) {
	Position P = first(*pL), E = endList(*pL), Q;
	while (P != E) {
		Q = next(P, *pL);
		while (Q != E) {
			if (retrieve(P, *pL) > retrieve(Q, *pL))
			{
				ElementType x = retrieve(P, *pL);
				ElementType y = retrieve(Q, *pL);
				deleteList(P, pL);
				insertList(y, P, pL);
				deleteList(Q, pL);
				insertList(x, Q, pL);
			}
			else
				Q = next(Q, *pL);
		}
		P = next(P, *pL);
	}
}

int main() {

	List L;
	Position p;

	L = (struct Node*)malloc(sizeof(struct Node));
	L->Next = NULL;
	int i;
	for (i = 5; i >= 1; i--)
		append(2 * i, &L);

	sort(&L);
	p = L;
	while (p->Next != NULL)
	{
		printf("%d ", p->Next->Element);
		p = p->Next;
	}

	return 0;
}