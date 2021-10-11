/*
	output:
	B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00 - 9.50
	B1806973 - Thai Anh - 4.50 - 1.25 - 1.00 - 6.75
	Nộp code trên ELSE:
	typedef struct SinhVien ElementType;
	typedef int Position;
	hàm endList(), retrieve() và hienthi()
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

Position endList(DanhSach L) {
	return L.n + 1;
}

ElementType retrieve(Position P, DanhSach L) {
	return L.A[P - 1];
}

void hienthi(DanhSach L) {
	for (Position i = 1; i < endList(L); i++)
		printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", retrieve(i, L).MSSV, retrieve(i, L).HoTen, retrieve(i, L).DiemLT, retrieve(i, L).DiemTH1, retrieve(i, L).DiemTH2,
			retrieve(i, L).DiemLT + retrieve(i, L).DiemTH1 + retrieve(i, L).DiemTH2);
}

int main()
{
	DanhSach L = { {{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1 };
	struct SinhVien s = { "B1806973","Thai Anh", 4.5f, 1.25f, 1.0f };
	L.A[1] = s;
	L.n++;
	hienthi(L);
	return 0;
}