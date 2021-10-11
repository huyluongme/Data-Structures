/*
	input:
	5
	1 2 3 4 5
	output:
	5
	Nộp code trên ELSE: hàm maxList()
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

void readList(List* pL) {
	makenullList(pL);
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		insertList(x, endList(*pL), pL);
	}
}

void printList(List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		printf("%d ", retrieve(P, L));
		P = next(P, L);
	}
}

ElementType maxList(List L) {
	ElementType min = retrieve(first(L), L);
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (min < retrieve(P, L))
			min = retrieve(P, L);
		P = next(P, L);
	}
	return min;
}

int main()
{
	List L;
	readList(&L);
	printf("%d", maxList(L));
	return 0;
}