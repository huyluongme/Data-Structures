/*
output:
Khong dat:
B1806872 - Minh Dong - 1.50 - 1.00 - 1.00
B1818973 - Dong Nghi - 0.50 - 1.25 - 1.00

Nộp code trên ELSE:
typedef struct SinhVien ElementType;
typedef int Position;
hàm first(), endList(), retrieve() và chepKhongDat()
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

int ktDay(DanhSach L) {
	return L.n == MaxLenght;
}

Position first(DanhSach L) {
	return 1;
}

Position endList(DanhSach L) {
	return L.n + 1;
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

DanhSach chepKhongDat(DanhSach L) {
	DanhSach result = dsRong();

	for (Position i = first(L); i < endList(L); i++)
		if (retrieve(i, L).DiemLT + retrieve(i, L).DiemTH1 + retrieve(i, L).DiemTH2 < 4.0)
			chenCuoi(retrieve(i, L), &result);
	return result;
}

int main()
{
	int i;
	DanhSach L1;
	DanhSach L = { {{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1 };
	struct SinhVien s1 = { "B1806872","Minh Dong", 1.5f, 1.0f, 1.0f };
	struct SinhVien s2 = { "B1806973","Thai Anh", 4.5f, 1.25f, 1.0f };
	struct SinhVien s3 = { "B1818973","Dong Nghi", 0.5f, 1.25f, 1.0f };
	L.A[1] = s1;
	L.n++;
	L.A[2] = s2;
	L.n++;
	L.A[3] = s3;
	L.n++;
	L1 = chepKhongDat(L);
	printf("Khong dat:\n");
	for (i = 0; i <= L1.n - 1; i++)
	{
		printf("%s - %s - %.2f - %.2f - %.2f\n", L1.A[i].MSSV, L1.A[i].HoTen, L1.A[i].DiemLT, L1.A[i].DiemTH1, L1.A[i].DiemTH2);
	}
	return 0;
}