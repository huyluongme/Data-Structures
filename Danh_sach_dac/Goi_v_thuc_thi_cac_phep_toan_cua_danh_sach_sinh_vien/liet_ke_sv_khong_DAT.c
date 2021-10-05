/* 
Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một danh sách đặc. Mỗi sinh viên (cấu trúc SinhVien) là một phần tử trong danh sách đặc có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (float).

Khi biểu diễn bằng danh sách đặc DanhSach, người ta dùng một cấu trúc có 2 trường:

   - Mảng A chứa các sinh viên

   - Số phần tử trong danh sách: n



Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.


Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên. Sau đó liệt kê những sinh viên KHÔNG ĐẠT.
*/

#include <stdio.h>
#include <string.h>

#define Maxlength 40

struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};

typedef struct
{
    struct SinhVien A[Maxlength];
    int n;
} DanhSach;

void dsRong(DanhSach *pL)
{
    pL->n = 0;
}

void nhapDS(DanhSach *pL)
{
    dsRong(pL);
    scanf("%d", &pL->n);
    getchar();
    for (int i = 1; i <= pL->n; i++)
    {
        fgets(pL->A[i - 1].MSSV, 10, stdin);
        if (pL->A[i - 1].MSSV[strlen(pL->A[i - 1].MSSV) - 1] == '\n')
            pL->A[i - 1].MSSV[strlen(pL->A[i - 1].MSSV) - 1] = '\0';

        fgets(pL->A[i - 1].HoTen, 50, stdin);
        if (pL->A[i - 1].HoTen[strlen(pL->A[i - 1].HoTen) - 1] == '\n')
            pL->A[i - 1].HoTen[strlen(pL->A[i - 1].HoTen) - 1] = '\0';

        scanf("%f%f%f", &pL->A[i - 1].DiemLT, &pL->A[i - 1].DiemTH1, &pL->A[i - 1].DiemTH2);
        getchar();
    }
}

void hienthiDS(DanhSach L)
{
    for (int i = 1; i <= L.n; i++)
    {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen,
               L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
    }
}

void hienthikhongDat(DanhSach L)
{
    printf("Sinh vien KHONG DAT\n");
    for (int i = 1; i <= L.n; i++)
    {
        if ((L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2) < 4.0f)
            printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen,
                   L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
    }
}

int main()
{
    DanhSach L;
    nhapDS(&L);
    hienthiDS(L);
    hienthikhongDat(L);
}