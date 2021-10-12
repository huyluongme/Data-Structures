/*
output:
Found 50
Nộp code trên ELSE: hàm first(), endList(), next(), retrieve() và locate()
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

int main()
{
	List L;
	Position p, q;
	ElementType x;

	L = (struct Node*)malloc(sizeof(struct Node));
	L->Next = NULL;

	p = L;
	q = (struct Node*)malloc(sizeof(struct Node));
	q->Element = 5;
	q->Next = NULL;
	p->Next = q;

	p = p->Next;
	q = (struct Node*)malloc(sizeof(struct Node));
	q->Element = 50;
	q->Next = NULL;
	p->Next = q;

	x = 50;
	q = locate(x, L);
	if (q->Next != NULL)
		printf("Found %d", x);
	else printf("Not found %d", x);
	return 0;
}