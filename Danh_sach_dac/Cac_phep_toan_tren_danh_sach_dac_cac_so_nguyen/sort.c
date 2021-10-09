/*
output:
2 4 6 8 10
Nộp bài trên ELSE: Hàm first(), endList(), next(), retrieve(), deleteList() và sort()
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

void deleteList(Position P, List* pL) {
	if (emptyList(*pL))
		printf("Danh sach rong\n");
	else if (P < first(*pL) || P > endList(*pL) - 1)
		printf("Vi tri khong hop le\n");
	else {
		for (Position i = P; i < endList(*pL) - 1; i++)
			pL->Elements[i - 1] = pL->Elements[i];
		pL->Last--;
	}
}

void sort(List* pL) {
	Position P = first(*pL), E = endList(*pL), Q;
	while (P != E) {
		Q = next(P, *pL);
		while (Q != E) {
			if (retrieve(P, *pL) > retrieve(Q, *pL)) {
				ElementType x = retrieve(P, *pL), y = retrieve(Q, *pL);
				deleteList(P, pL);
				insertList(y, P, pL);
				deleteList(Q, pL);
				insertList(x, Q, pL);
			}
			Q = next(Q, *pL);
			E = endList(*pL);
		}
		P = next(P, *pL);
	}
}

int main()
{
	List L;
	int i;
	L.Last = 0;
	for (i = 5; i >= 1; i--) {
		L.Elements[5 - i] = 2 * i;
	}
	L.Last = 5;
	sort(&L);

	for (i = 0; i < L.Last; i++) {
		printf("%d ", L.Elements[i]);
	}
	return 0;
}