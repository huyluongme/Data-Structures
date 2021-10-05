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

void them(int x, NganXep* pS)
{
	if (!ktDay(*pS))
	{
		pS->Dinh = pS->Dinh - 1;
		pS->DuLieu[pS->Dinh] = x;
	}
}

int main()
{
	NganXep S;
	S.Dinh = 100;
	them(10, &S);
	printf("%d", S.DuLieu[S.Dinh]);
	return 0;
}