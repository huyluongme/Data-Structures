﻿/*
	output:
	2 4 6 8 10 12 14 16 18
	Nộp code trên ELSE: Hàm erase()
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

Position locate(ElementType x, List L) {
	Position P = first(L);
	Position E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == x)
			return P;
		else
			P = next(P, L);
	}
	return P;
}

void erase(ElementType x, List* pL) {
	Position P = locate(x, *pL);
	deleteList(P, pL);
}

int main()
{
	List L;
	int i;
	L.Last = 0;
	for (i = 0; i < 10; i++)
	{
		L.Elements[i] = 2 * i;
	}
	L.Last = 10;
	erase(0, &L);
	for (i = 0; i < L.Last; i++)
	{
		printf("%d ", L.Elements[i]);
	}
	return 0;
}