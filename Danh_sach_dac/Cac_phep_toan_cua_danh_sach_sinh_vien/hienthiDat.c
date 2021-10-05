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



Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.

Giả sử khai báo kiểu DanhSach đã được định nghĩa.  Hãy viết 1 hàm hiển thị danh sách sinh viên ĐẠT.
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

void hienthiDat(DanhSach L)
{
    for (int i = 1; i <= L.n; i++)
    {
        if ((L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2) >= 4.0f)
        {
            printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2, L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2);
        }
    }
}

int main()
{
    DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
struct SinhVien s1 = {"B1806872","Minh Dong", 1.5f, 1.0f, 1.0f}; 
struct SinhVien s2 = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
L.A[1] = s1;
L.n++;
L.A[2] = s2;
L.n++;
hienthiDat(L);
}