/*
	output:
	1
	Nộp code trên ELSE: hàm first(), endList(), next(), retrieve() và normalize()
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

void deleteList(Position P, List* pL) {
	if (next(P, *pL) != NULL) {
		Position tmp = P->Next;
		P->Next = tmp->Next;
		free(tmp);
	}
}

void normalize(List* pL)
{
	Position P = first(*pL), E = endList(*pL), Q;
	while (P != E)
	{
		Q = next(P, *pL);
		while (Q != E)
		{
			if (retrieve(P, *pL) == retrieve(Q, *pL)) {
				deleteList(Q, pL);
				E = endList(*pL);
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

	append(1, &L);
	append(1, &L);
	append(1, &L);


	normalize(&L);
	p = L;
	while (p->Next != NULL)
	{
		printf("%d ", p->Next->Element);
		p = p->Next;
	}
	return 0;
}