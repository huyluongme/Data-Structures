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

int main()
{
	NganXep S;
	S.Dinh = 10;
	printf("%d ", S.Dinh);
	khoitao(&S);
	printf("%d ", S.Dinh);

	return 0;
}