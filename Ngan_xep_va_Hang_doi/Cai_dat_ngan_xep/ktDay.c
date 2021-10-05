#include <stdio.h>

#define SoPhanTu 100
typedef int ElementType;

typedef struct {
	ElementType DuLieu[SoPhanTu];
	int Dinh;
}NganXep;

int ktDay(NganXep S)
{
	return S.Dinh == 0;
}

int main()
{
	NganXep S;
	S.Dinh = 0;
	if (ktDay(S))
		printf("Ngan xep day");
	else  printf("Ngan xep chua day");

	return 0;
}