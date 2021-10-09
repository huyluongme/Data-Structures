/*
output:
0 in L
Nộp code trên ELSE: Hàm first(), endList(), next(), retrieve() và member()
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

int member(ElementType x, List L) {
	Position P = first(L);
	Position E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == x)
			return 1;
		else
			P = next(P, L);
	}
	return 0;
}

int main()
{
	List L;
	int i;
	L.Last = 0;
	for (i = 0; i < 5; i++)
		L.Elements[i] = 2 * i;
	L.Last = 5;
	if (member(0, L))
		printf("0 in L");
	else printf("0 not in L");
	return 0;
}