/*
	output:
	B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00
	B1806973 - Thai Anh - 4.50 - 1.25 - 1.00
	Nộp code trên ELSE:
	#define MaxLenght 40
	hàm ktDay() và chenCuoi()
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

int ktDay(DanhSach L) {
	return L.n == MaxLenght;
}

void chenCuoi(struct SinhVien s, DanhSach* pL) {
	if (ktDay(*pL))
		printf("Loi! Danh sach day!");
	else {
		pL->A[pL->n] = s;
		pL->n++;
	}
}

int main()
{
	DanhSach L = { {{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1 };
	struct SinhVien s = { "B1806973","Thai Anh", 4.5f, 1.25f, 1.0f };
	int i;
	chenCuoi(s, &L);
	for (i = 0; i < L.n; i++)
	{
		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}
	return 0;
}