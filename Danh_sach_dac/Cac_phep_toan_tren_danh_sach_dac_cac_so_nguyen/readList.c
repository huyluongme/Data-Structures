/*
	input: 
	5
	1 3 5 7 9
	output:
	1 3 5 7 9
	Nộp code trên ELSE: Hàm endList() và readList()
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

void readList(List* pL) {
	makenullList(pL);
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		insertList(x, endList(*pL), pL);
	}
}

int main()
{
	List L;
	int i;
	readList(&L);
	for (i = 0; i < L.Last; i++)
	{
		printf("%d ", L.Elements[i]);
	}
	return 0;
}