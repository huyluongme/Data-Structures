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

Giả sử khai báo kiểu DanhSach đã được khai báo.  Các phép toán bên dưới cũng được định nghĩa:

  - Trả về 1 danh sách rỗng: dsRong()

  - Chèn 1 sinh viên vào cuối danh sách: chenCuoi()



Hãy viết 1 hàm chép những sinh viên KHÔNG ĐẠT trong danh sách thứ nhất sang danh sách kết quả
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

DanhSach dsRong()
{
    DanhSach L;
    L.n = 0;
    return L;
}

int ktDay(DanhSach L)
{
    return L.n == Maxlength;
}

void chenCuoi(struct SinhVien s, DanhSach *pL)
{
    if (ktDay(*pL) == 1)
        printf("Loi! Danh sach day!");
    else
    {
        pL->A[pL->n] = s;
        pL->n++;
    }
}

DanhSach chepKhongDat(DanhSach L)
{
    DanhSach L_KhongDat = dsRong();
    for (int i = 1; i <= L.n; i++)
    {
        if ((L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2) < 4.0f)
        {
            chenCuoi(L.A[i - 1], &L_KhongDat);
        }
    }
    return L_KhongDat;
}

int main()
{
    int i;
    DanhSach L1;
    DanhSach L = {{{"B1806972", "Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
    struct SinhVien s1 = {"B1806872", "Minh Dong", 1.5f, 1.0f, 1.0f};
    struct SinhVien s2 = {"B1806973", "Thai Anh", 4.5f, 1.25f, 1.0f};
    struct SinhVien s3 = {"B1818973", "Dong Nghi", 0.5f, 1.25f, 1.0f};
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