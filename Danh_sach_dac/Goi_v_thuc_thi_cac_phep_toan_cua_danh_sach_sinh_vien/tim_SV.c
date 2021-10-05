/* 
Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một danh sách đặc. Mỗi sinh viên (cấu trúc SinhVien) là một phần tử trong danh sách đặc có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (float).

Khi biểu diễn bằng danh sách đặc DanhSach, người ta dùng một cấu trúc có 2 trường:

   - Mảng A chứa các sinh viên

   - Số phần tử trong danh sách: n


Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên. Sau đó nhập một mã số sinh viên từ bàn phím, nếu mã số tồn tại thì xóa sinh viên có mã số đó.
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

int tim(char x[], DanhSach L)
{
    for (int i = 1; i <= L.n; i++)
    {
        if (strcmp(L.A[i - 1].MSSV, x) == 0)
            return i;
    }
    return L.n + 1;
}

int main()
{
    DanhSach L;
    nhapDS(&L);
    char t_MSSV[10];
    fgets(t_MSSV, 10, stdin);
    if (t_MSSV[strlen(t_MSSV) - 1] == '\n')
        t_MSSV[strlen(t_MSSV) - 1] = '\0';
    hienthiDS(L);
    int id = tim(t_MSSV, L);
    if (id != L.n + 1)
        printf("Tim thay sinh vien %s. Thong tin sinh vien:\n%s - %s - %.2f - %.2f - %.2f\n", t_MSSV, L.A[id - 1].MSSV, L.A[id - 1].HoTen,
               L.A[id - 1].DiemLT, L.A[id - 1].DiemTH1, L.A[id - 1].DiemTH2);
    else
        printf("Khong tim thay sinh vien %s", t_MSSV);
}