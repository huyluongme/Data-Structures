/*
output:
0 2 4 6 8
Nộp code trên ELSE: #define MaxLenght 100, hàm fullList(), first(), endList() và insertList()
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

Position next(Position P, List L) {
	return P + 1;
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

int main()
{
	List L;
	int i;
	L.Last = 0;
	for (i = 0; i < 5; i++)
	{
		insertList(i * 2, L.Last + 1, &L);
	}
	for (i = 0; i < L.Last; i++)
	{
		printf("%d ", L.Elements[i]);
	}
	return 0;
}