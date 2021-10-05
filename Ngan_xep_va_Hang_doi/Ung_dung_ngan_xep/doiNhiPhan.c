#include <stdio.h>

#define SoPhanTu 100
typedef int ElementType;

typedef struct {
	ElementType DuLieu[SoPhanTu];
	int Dinh;
}NganXep;

void khoitao(NganXep* pS)
{
	pS->Dinh = SoPhanTu;
}

int ktRong(NganXep S)
{
	return S.Dinh == SoPhanTu;
}

int ktDay(NganXep S)
{
	return S.Dinh == 0;
}

void them(int x, NganXep* pS)
{
	if (!ktDay(*pS))
	{
		pS->Dinh = pS->Dinh - 1;
		pS->DuLieu[pS->Dinh] = x;
	}
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

void doiNhiPhan(int n, NganXep* pS)
{
	khoitao(pS);
	while (n != 0)
	{
		them(n % 2, pS);
		n /= 2;
	}
}

int main()
{
	NganXep S;
	int n;
	scanf("%d", &n);
	doiNhiPhan(n, &S);
	hienthi(&S);
	return 0;
}