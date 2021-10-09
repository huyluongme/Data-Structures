/*
output:
AVG = 3.0000
Nộp code trên ELSE: Hàm emptyList(), first(), endList(), next(), retrieve() và getAvg()
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

ElementType retrieve(Position P, List L) {
	return L.Elements[P - 1];
}

float getAvg(List L) {
	if (!emptyList(L)) {
		float S = 0.0;
		Position P = first(L), E = endList(L);
		while (P != E) {
			S += retrieve(P, L);
			P = next(P, L);
		}
		return S / (endList(L) - 1);
	}
	else {
		return -10000.0;
	}
}

int main()
{
	List L;
	int i;
	L.Last = 0;
	for (i = 0; i < 5; i++)
		L.Elements[i] = i + 1;
	L.Last = 5;
	printf("AVG = %.4f\n", getAvg(L));
	return 0;
}