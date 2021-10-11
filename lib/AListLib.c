#include <stdio.h>

#define MaxLenght 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLenght];
	Position Last;
}List;

void makenullList(List* pL){
	pL->Last = 0;
}

int emptyList(List L){
	return L.Last == 0;
}

int fullList(List L){
	return L.Last == MaxLenght;
}

Position first(List L){
	return 1;
}

Position endList(List L) {
	return L.Last + 1;
}

Position next(Position P, List L) {
	return P + 1;
}

Position previous(Position P, List L) {
	return P - 1;
}

ElementType retrieve(Position P, List L) {
	return L.Elements[P - 1];
}

void insertList(ElementType X, Position P, List* pL) {
	if (fullList(*pL))
		printf("Danh sach day");
	else if (P < 1 || P > endList(*pL))
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

Position locate(ElementType X, List L) {
	Position P = first(L);
	Position E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == X)
			return P;
		else
			P = next(P, L);
	}
}
