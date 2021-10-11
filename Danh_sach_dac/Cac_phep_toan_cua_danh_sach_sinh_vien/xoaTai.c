/*
output:
B1806972 - Hoang Minh - 5.50 - 2.50 - 2.00
B1806973 - Thai Anh - 4.50 - 1.25 - 1.00

B1806973 - Thai Anh - 4.50 - 1.25 - 1.00

Nộp code trên ELSE:
typedef int Position;
hàm first(), endList() và xoaTai()
*/
#include <stdio.h>

#define MaxLenght 40

struct SinhVien {
	char MSSV[10];
	char HoTen[50];
	float DiemLT, DiemTH1, DiemTH2;
};

typedef struct SinhVien ElementType;
typedef int Position;

typedef struct {
	ElementType A[MaxLenght];
	Position n;
}DanhSach;

Position first(DanhSach L) {
	return 1;
}

Position endList(DanhSach L) {
	return L.n + 1;
}

int xoaTai(Position P, DanhSach* pL) {
	if (P < first(*pL) || P > endList(*pL) - 1)
		return 0;
	else {
		for (Position i = P; i < endList(*pL) - 1; i++)
			pL->A[P - 1] = pL->A[P];
		pL->n--;
		return 1;
	}
}

int main()
{
	DanhSach L = { {{"B1806972","Hoang Minh", 5.5f, 2.5f, 2.0f}}, 1 };
	struct SinhVien s = { "B1806973","Thai Anh", 4.5f, 1.25f, 1.0f };
	int i;
	L.A[1] = s;
	L.n++;
	for (i = 0; i < L.n; i++)
	{
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}
	xoaTai(1, &L);
	printf("\n");
	for (i = 0; i < L.n; i++)
	{
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}
	return 0;
}