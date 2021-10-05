#include <stdio.h>

#define SoPhanTu 100
typedef int ElementType;

typedef struct {
	ElementType DuLieu[SoPhanTu];
	int Dinh;
}NganXep;

int giatriDinh(NganXep S)
{
	return S.DuLieu[S.Dinh];
}

int main()
{
	NganXep S;
    S.Dinh=99;
    S.DuLieu[S.Dinh]=10;
    printf("%d",giatriDinh(S));
	return 0;
}