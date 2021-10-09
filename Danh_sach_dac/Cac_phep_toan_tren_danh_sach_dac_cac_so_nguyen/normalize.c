/*
output:
0 14 10 -100
Nộp code trên ELSE: Hàm first(), endList(), next(), retrieve() và normalize()
*/
#include <stdio.h>

#define MaxLenght 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLenght];
	Position Last;
}List;

int emptyList(List L) {
	return L.Last == 0;
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

ElementType retrieve(Position P, List L) {
	return L.Elements[P - 1];
}

void normalize(List* pL) {
	Position P = first(*pL), E = endList(*pL), Q;
	while (P != E) {
		Q = next(P, *pL);
		while (Q != E) {
			if (retrieve(P, *pL) == retrieve(Q, *pL)) {
				deleteList(Q, pL);
				E = endList(*pL);
			}
			else
				Q = next(Q, *pL);
		}
		P = next(P, *pL);
	}
}

int main()
{
	List L;
	int i;
	L.Last = 6;
	L.Elements[0] = 0;
	L.Elements[1] = 14;
	L.Elements[2] = 10;
	L.Elements[3] = -100;
	L.Elements[4] = 14;
	L.Elements[5] = 14;
	normalize(&L);
	for (i = 0; i < L.Last; i++)
	{
		printf("%d ", L.Elements[i]);
	}
	return 0;
}