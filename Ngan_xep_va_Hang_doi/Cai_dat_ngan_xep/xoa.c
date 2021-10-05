#include <stdio.h>

#define SoPhanTu 100
typedef int ElementType;

typedef struct {
	ElementType DuLieu[SoPhanTu];
	int Dinh;
}NganXep;

void xoa(NganXep* pS)
{
	pS->Dinh = pS->Dinh + 1;
}

int main()
{
	NganXep S;
	S.Dinh = 99;
	S.DuLieu[S.Dinh] = 10;
	xoa(&S);
	if (S.Dinh == SoPhanTu)
		printf("Ngan xep rong");
	else
		printf("Ngan xep khong rong");
	return 0;
}