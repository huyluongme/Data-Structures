/*
input:
5
1 2 3 4 5
4
output:
1
Nộp code trên ELSE: hàm countList()
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

Position locate(ElementType X, List L) {
	Position P = first(L);
	Position E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == X)
			return P;
		else
			P = next(P, L);
	}
	return P;
}

void insertList(ElementType X, Position P, List* pL) {
	if (fullList(*pL))
		printf("Danh sach day");
	else if (P < first(*pL) || P > endList(*pL))
		printf("Vi tri khong hop le");
	else {
		for (Position i = endList(*pL) - 1; i >= P; i--)
			pL->Elements[i] = pL->Elements[i - 1];
		pL->Elements[P - 1] = X;
		pL->Last++;
	}
}

void deleteList(Position P, List* pL) {
	if (emptyList(*pL))
		printf("Danh sach rong");
	else if (P < 1 || P > endList(*pL))
		printf("Vi tri khong hop le");
	else {
		for (Position i = P; i < endList(*pL) - 1; i++)
			pL->Elements[i - 1] = pL->Elements[i];
		pL->Last--;
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

void deleteX(ElementType x, List* pL) {
	Position P = locate(x, *pL);
	if (P != endList(*pL))
		deleteList(P, pL);
}

int countList(ElementType X, List L) {
	int count = 0;
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == X)
			count++;
		P = next(P, L);
	}
	return count;
}

int main()
{
	List L;
	readList(&L);
	int x;
	scanf("%d", &x);
	printf("%d", countList(x, L));
	return 0;
}