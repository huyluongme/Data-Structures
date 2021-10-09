/*
	output:
	0 at 1
	Nộp code trên ELSE: Hàm first(), endList(), next(), retrieve() và locate()
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

int main()
{
	List L;
	int i;
	Position p;
	L.Last = 0;
	for (i = 0; i <= 6; i++)
		L.Elements[i] = 2 * i;

	for (i = 0; i <= 10; i++)
		L.Elements[i] = 2 * i;

	L.Last = 11;
	p = locate(0, L);
	printf("0 at %d", p);
	return 0;
}