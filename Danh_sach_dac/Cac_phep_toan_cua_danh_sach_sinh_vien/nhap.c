/*
	input:
	3
	B1804965
	Nguyen Thai Anh
	3 2.5 2
	B1806421
	Chau My Linh
	3.25 2 2.5
	B1804965
	Ha Phu Dong
	3.5 2.5 2.5

	output:
	B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00
	B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50

	Nộp code trên ELSE:
	typedef int Position;
	hàm endList() và nhap()
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

DanhSach dsRong() {
	DanhSach L;
	L.n = 0;
	return L;
}

Position first(DanhSach L) {
	return 1;
}

int ktDay(DanhSach L) {
	return L.n == MaxLenght;
}

Position endList(DanhSach L) {
	return L.n + 1;
}

Position next(Position P, DanhSach L) {
	return P + 1;
}

ElementType retrieve(Position P, DanhSach L) {
	return L.A[P - 1];
}

void chenCuoi(struct SinhVien s, DanhSach* pL) {
	if (ktDay(*pL))
		printf("Loi! Danh sach day!");
	else {
		pL->A[pL->n] = s;
		pL->n++;
	}
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

DanhSach nhap() {
	DanhSach L = dsRong();
	int n;
	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++) {
		struct SinhVien s;
		fgets(s.MSSV, sizeof(s.MSSV), stdin);
		if (s.MSSV[strlen(s.MSSV) - 1] == '\n')
			s.MSSV[strlen(s.MSSV) - 1] = '\0';

		fgets(s.HoTen, sizeof(s.HoTen), stdin);
		if (s.HoTen[strlen(s.HoTen) - 1] == '\n')
			s.HoTen[strlen(s.HoTen) - 1] = '\0';

		scanf("%f%f%f%*c", &s.DiemLT, &s.DiemTH1, &s.DiemTH2);
		if (tim(s.MSSV, L) == endList(L))
			chenCuoi(s, &L);
	}
	return L;
}

int main()
{
	DanhSach L;
	int i;

	L = nhap();
	for (i = 0; i <= L.n - 1; i++)
	{
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}
	return 0;
}