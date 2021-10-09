/*
	output:
	0 2 4 6 8 0 8
	Nộp code trên ELSE: #define MaxLenght 100, fullList(), first(), endList(), insertList() và insertSet()
*/
#include <stdio.h>

#define MaxLenght 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLenght];
	Position Last;
}List;

int fullList(List L) {
	return L.Last == MaxLenght;
}

Position first(List L) {
	return 1;
}

Position endList(List L) {
	return L.Last + 1;
}

void insertList(ElementType x, Position P, List* pL) {
	if (fullList(*pL))
		printf("Danh sach day");
	else if (P < first(*pL) || P > endList(*pL))
		printf("Vi tri khong hop le");
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

int main()
{
	List L;
	int i;
	L.Last = 0;
	for (i = 0; i != 5; i++)
		insertSet(2 * i, &L);
	insertSet(0, &L);
	insertSet(8, &L);
	for (i = 0; i < L.Last; i++)
	{
		printf("%d ", L.Elements[i]);
	}
	return 0;
}