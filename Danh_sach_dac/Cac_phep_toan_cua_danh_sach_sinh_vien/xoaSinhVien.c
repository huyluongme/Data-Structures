/*
	output:
	B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00
	B1806973 - Thai Anh - 4.50 - 1.25 - 1.00

	B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00
	Nộp code trên ELSE:
	typedef int Position;
	hàm endList() và xoaSinhVien()
*/
#include <stdio.h>
#include <string.h>

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

ElementType retrieve(Position P, DanhSach L) {
	return L.A[P - 1];
}

Position next(Position P, DanhSach L) {
	return P + 1;
}

Position tim(char x[], DanhSach L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (strcmp(retrieve(P, L).MSSV, x) == 0)
			return P;
		else
			P = next(P, L);
	}
	return P;
}

void xoaTai(Position P, DanhSach* pL) {
	for (Position i = P; i < endList(*pL) - 1; i++)
		pL->A[P - 1] = pL->A[P];
	pL->n--;
}

void xoaSinhVien(char x[], DanhSach* pL) {
	Position P = tim(x, *pL);
	if (P != endList(*pL))
		xoaTai(P, pL);
}

int main()
{
	DanhSach L = { {{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1 };
	struct SinhVien s = { "B1806973","Thai Anh", 4.5f, 1.25f, 1.0f };
	int i;
	L.A[1] = s;
	L.n++;
	for (i = 0; i < L.n; i++)
	{
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}
	xoaSinhVien("B1806973", &L);
	printf("\n");
	for (i = 0; i < L.n; i++)
	{
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}
	return 0;
}