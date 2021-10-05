#include <stdio.h>

#define SoPhanTu 100
typedef int ElementType;

typedef struct {
	ElementType DuLieu[SoPhanTu];
	int Dinh;
}NganXep;

int ktRong(NganXep S)
{
	return S.Dinh == SoPhanTu;
}


int main()
{
	NganXep S;
	S.Dinh = 10;
	if (ktRong(S))
		printf("Ngan xep rong");
	else  printf("Ngan xep khong rong");
	return 0;
}