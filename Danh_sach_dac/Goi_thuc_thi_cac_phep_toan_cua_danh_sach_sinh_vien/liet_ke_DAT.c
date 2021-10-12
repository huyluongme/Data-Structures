/*
	input:
	2
	B1804965
	Nguyen Thai Anh
	3 2.5 2
	B1806421
	Chau My Linh
	3.25 2 2.5

	output:
	B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00
	B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50
	Sinh vien DAT
	B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00
	B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50
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

int ktRong(DanhSach L) {
	return L.n == 0;
}

int ktDay(DanhSach L) {
	return L.n == MaxLenght;
}

Position vtDau(DanhSach L) {
	return 1;
}

Position vtsauCuoi(DanhSach L) {
	return L.n + 1;
}

Position vtketiep(Position P, DanhSach L) {
	return P + 1;
}

ElementType retrieve(Position P, DanhSach L) {
	return L.A[P - 1];
}

Position tim(char x[], DanhSach L) {
	Position P = vtDau(L), E = vtsauCuoi(L);
	while (P != E) {
		if (strcmp(retrieve(P, L).MSSV, x) == 0)
			return P;
		else
			P = vtketiep(P, L);
	}
	return P;
}

void chenCuoi(struct SinhVien s, DanhSach* pL) {
	if (ktDay(*pL))
		printf("Loi! Danh sach day!");
	else {
		pL->A[pL->n] = s;
		pL->n++;
	}
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
		if (tim(s.MSSV, L) == vtsauCuoi(L))
			chenCuoi(s, &L);
	}
	return L;
}

void hienthi(DanhSach L) {
	for (Position i = vtDau(L); i < vtsauCuoi(L); i++)
		printf("%s - %s - %.2f - %.2f - %.2f\n", retrieve(i, L).MSSV, retrieve(i, L).HoTen, retrieve(i, L).DiemLT, retrieve(i, L).DiemTH1, retrieve(i, L).DiemTH2);
}

void hienthiDAT(DanhSach L) {
	printf("Sinh vien DAT\n");
	for (Position i = vtDau(L); i < vtsauCuoi(L); i++)
		if (retrieve(i, L).DiemLT + retrieve(i, L).DiemTH1 + retrieve(i, L).DiemTH2 >= 4.0)
			printf("%s - %s - %.2f - %.2f - %.2f\n", retrieve(i, L).MSSV, retrieve(i, L).HoTen, retrieve(i, L).DiemLT, retrieve(i, L).DiemTH1, retrieve(i, L).DiemTH2);
}

void hienthiKHONGDAT(DanhSach L) {
	printf("Sinh vien KHONG DAT\n");
	for (Position i = vtDau(L); i < vtsauCuoi(L); i++)
		if (retrieve(i, L).DiemLT + retrieve(i, L).DiemTH1 + retrieve(i, L).DiemTH2 < 4.0)
			printf("%s - %s - %.2f - %.2f - %.2f\n", retrieve(i, L).MSSV, retrieve(i, L).HoTen, retrieve(i, L).DiemLT, retrieve(i, L).DiemTH1, retrieve(i, L).DiemTH2);
}

int main() {
	DanhSach L = nhap();
	hienthi(L);
	hienthiDAT(L);
	return 0;
}