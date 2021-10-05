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

void xoa(NganXep* pS)
{
	pS->Dinh = pS->Dinh + 1;
}

int giatriDinh(NganXep S)
{
	return S.DuLieu[S.Dinh];
}

void hienthi(NganXep* pS)
{
	while (!ktRong(*pS))
	{
		printf("%d ", giatriDinh(*pS));
		xoa(pS);
	}
}

int main()
{
	NganXep S;
	S.Dinh = 99;
	S.DuLieu[S.Dinh] = 10;
	hienthi(&S);
	return 0;
}