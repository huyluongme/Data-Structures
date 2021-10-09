/*
	output: 
	0 4 6 8
	Nộp code trên ELSE: Hàm emptyList(), first(), endList(), deleteList()
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

int main()
{
	List L;
	int i;
	L.Last = 0;
	for (i = 0; i < 5; i++)
	{
		L.Elements[i] = 2 * i;
	}
	L.Last = 5;
	deleteList(2, &L);
	for (i = 0; i < L.Last; i++)
	{
		printf("%d ", L.Elements[i]);
	}
	return 0;
}