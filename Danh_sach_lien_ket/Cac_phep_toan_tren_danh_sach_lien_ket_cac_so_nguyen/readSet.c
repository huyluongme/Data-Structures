/*
	input:
	4
	1 -10 2 2
	output:
	2 -10 1
	Nộp code trên ELSE: hàm readSet()
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

int member(ElementType x, List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == x)
			return 1;
		P = next(P, L);
	}
	return 0;
}

void addFirst(ElementType x, List* pL) {
	Position P = *pL;
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}

List readSet() {
	List L;
	makenullList(&L);
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (!member(x, L))
			addFirst(x, &L);
	}
	return L;
}


int main() {

	List L;
	Position p;
	L = readSet();
	p = L;
	while (p->Next != NULL)
	{
		printf("%d ", p->Next->Element);
		p = p->Next;
	}
	return 0;
}