/*
output:
0 2 4 6 8
Nộp code trên ELSE: Hàm first(), endList(), next(), retrieve() và printList()
*/
#include <stdio.h>

#define MaxLenght 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLenght];
	Position Last;
}List;

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

void printList(List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		printf("%d ", retrieve(P, L));
		P = next(P, L);
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
	printList(L);
	return 0;
}