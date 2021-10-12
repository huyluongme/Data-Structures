/*
	output:
	1 11
	Nộp code trên ELSE:
	hàm first(), endList(), next(), retrieve(), printOddNumbers()
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

void printOddNumbers(List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (retrieve(P, L) % 2 != 0)
			printf("%d ", retrieve(P, L));
		P = next(P, L);
	}
}

int main() {

	List L;

	L = (struct Node*)malloc(sizeof(struct Node));
	L->Next = NULL;

	append(1, &L);
	append(10, &L);
	append(11, &L);

	printOddNumbers(L);
	return 0;
}