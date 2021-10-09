/*
output:
0 2 4 6 8 10
8 10 12 14 16
0 2 4 6 8 10 12 14 16
Nộp code trên ELSE: Hàm first(), endList(), next(), retrieve() và unionSet()
*/
#pragma warning(disable : 4996)

#include <stdio.h>

#define MaxLenght 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLenght];
	Position Last;
}List;

void makenullList(List* pL) {
	pL->Last = 0;
}

int emptyList(List L) {
	return L.Last == 0;
}

int fullList(List L) {
	return L.Last == MaxLenght;
}

Position first(List L) {
	return 1;
}

Position endList(List L) {
	return L.Last + 1;
}

Position next(Position P, List L) {
	return P + 1;
}

ElementType retrieve(Position P, List L) {
	return L.Elements[P - 1];
}

void insertList(ElementType x, Position P, List* pL) {
	if (fullList(*pL))
		printf("Danh sach day\n");
	else if (P < first(*pL) || P > endList(*pL))
		printf("Vi tri khong hop le\n");
	else {
		for (Position i = endList(*pL) - 1; i >= P; i--)
			pL->Elements[i] = pL->Elements[i - 1];
		pL->Elements[P - 1] = x;
		pL->Last++;
	}
}

void insertSet(ElementType x, List* pL) {
	insertList(x, endList(*pL), pL);
}

int member(ElementType x, List L) {
	Position P = first(L);
	Position E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == x)
			return 1;
		else
			P = next(P, L);
	}
	return 0;
}

void unionSet(List L1, List L2, List* pL) {
	makenullList(pL);
	Position P = first(L1), E = endList(L1);
	while (P != E) {
		insertSet(retrieve(P, L1), pL);
		P = next(P, L1);
	}

	P = first(L2);
	E = endList(L2);
	while (P != E) {
		if (!member(retrieve(P, L2), L1))
			insertSet(retrieve(P, L2), pL);
		P = next(P, L2);
	}
}

int main()
{
	List L1, L2, L;
	int i;

	makenullList(&L1);
	makenullList(&L2);

	for (i = 0; i <= 5; i++) {
		insertSet(2 * i, &L1);
	}
	for (i = 4; i <= 8; i++) {
		insertSet(2 * i, &L2);
	}

	for (i = 0; i < L1.Last; i++) {
		printf("%d ", L1.Elements[i]);
	}
	printf("\n");
	for (i = 0; i < L2.Last; i++) {
		printf("%d ", L2.Elements[i]);
	}
	printf("\n");
	unionSet(L1, L2, &L);
	for (i = 0; i < L.Last; i++) {
		printf("%d ", L.Elements[i]);
	}
	return 0;
}