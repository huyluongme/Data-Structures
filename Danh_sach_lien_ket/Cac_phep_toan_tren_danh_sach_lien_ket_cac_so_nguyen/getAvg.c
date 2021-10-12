/*
	output:
	AVG = -0.800
	Nộp code trên ELSE:
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

float getAvg(List L) {
	if (!emptyList(L)) {
		float result = 0.0;
		int count = 0;
		Position P = first(L), E = endList(L);
		while (P != E) {
			result += retrieve(P, L);
			P = next(P, L);
			count++;
		}
		return result / count;
	}
	else
		return -10000.0;
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

int main() {
	List L;
	L = (struct Node*)malloc(sizeof(struct Node));
	L->Next = NULL;

	append(20, &L);
	append(21, &L);
	append(-5, &L);
	append(10, &L);
	append(-50, &L);

	printf("AVG = %.3f", getAvg(L));
	return 0;
}