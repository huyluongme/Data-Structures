/*
	output:
	-1 9 -1
	Nộp code trên ELSE: Hàm first(), endList(), next(), retrieve() và printOddNumbers()
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

void printOddNumbers(List L) {
	Position P, E;
	P = first(L);
	E = endList(L);
	while (P != E) {
		if (retrieve(P, L) % 2 != 0)
			printf("%d ", retrieve(P, L));
		P = next(P, L);
	}
}

int main()
{
	List L;
	L.Elements[0] = -1;
	L.Elements[1] = 2;
	L.Elements[2] = 9;
	L.Elements[3] = -1;
	L.Elements[4] = -10;
	L.Last = 5;
	printOddNumbers(L);
	return 0;
}