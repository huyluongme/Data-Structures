/*
output:
0 1 2 3 4 5
0 2 4
Nộp code trên ELSE: Hàm first(), endList(), next(), retrieve() và copyEvenNumbers()
*/
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

void copyEvenNumbers(List L1, List* pL2) {
	makenullList(pL2);
	Position P = first(L1), E = endList(L1);
	while (P != E) {
		if (retrieve(P, L1) % 2 == 0)
			insertList(retrieve(P, L1), endList(*pL2), pL2);
		P = next(P, L1);
	}
}

int main()
{
	List L1, L2;
	int i;
	makenullList(&L1);
	for (i = 0; i <= 5; i++) {
		insertList(i, L1.Last + 1, &L1);
	}
	copyEvenNumbers(L1, &L2);
	for (i = 0; i < L1.Last; i++) {
		printf("%d ", L1.Elements[i]);
	}
	printf("\n");
	for (i = 0; i < L2.Last; i++) {
		printf("%d ", L2.Elements[i]);
	}
	return 0;
}