/* 
    Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một danh sách đặc. Mỗi sinh viên (cấu trúc SinhVien) là một phần tử trong danh sách đặc có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (float).

Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:

struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};


Khi biểu diễn bằng danh sách đặc DanhSach, người ta dùng một cấu trúc có 2 trường:
   - Mảng A chứa các sinh viên

   - Số phần tử trong danh sách: n



Giả sử khai báo kiểu DanhSach đã được định nghĩa.  Hãy viết 1 hàm xóa sinh viên ở vị trí p trong danh sách
*/

#include <stdio.h>

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

void xoaTai(int p, DanhSach *pL)
{
    if (p >= 1 && p <= pL->n)
    {
        for (int i = p; i <= pL->n; i++)
        {
            pL->A[p - 1] = pL->A[p];
        }
        pL->n--;
    }
}

int main()
{
    DanhSach L = {{{"B1806972", "Hoang Minh", 5.5f, 2.5f, 2.0f}}, 1};
    struct SinhVien s = {"B1806973", "Thai Anh", 4.5f, 1.25f, 1.0f};
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