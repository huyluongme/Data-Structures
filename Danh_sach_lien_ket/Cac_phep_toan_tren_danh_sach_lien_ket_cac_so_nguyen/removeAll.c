/*
output:
500
Nộp code trên ELSE: hàm endList() và removeAll()
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


Position locate(ElementType x, List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == x)
			return P;
		else
			P = next(P, L);
	}
	return P;
}

void removeAll(ElementType x, List* pL) {
	Position P = locate(x, *pL);
	while (P != endList(*pL)) {
		deleteList(P, pL);
		P = locate(x, *pL);
	}
}

int main() {
	List L;
	Position p, q;
	L = (struct Node*)malloc(sizeof(struct Node));
	L->Next = NULL;

	p = L;
	q = (struct Node*)malloc(sizeof(struct Node));
	q->Element = 5000;
	q->Next = NULL;
	p->Next = q;

	p = L;

	q = (struct Node*)malloc(sizeof(struct Node));
	q->Element = 500;
	q->Next = p->Next;
	p->Next = q;

	p = L;

	q = (struct Node*)malloc(sizeof(struct Node));
	q->Element = 5000;
	q->Next = p->Next;
	p->Next = q;


	removeAll(5000, &L);
	p = L;
	while (p->Next != NULL)
	{
		printf("%d ", p->Next->Element);
		p = p->Next;
	}
	return 0;
}