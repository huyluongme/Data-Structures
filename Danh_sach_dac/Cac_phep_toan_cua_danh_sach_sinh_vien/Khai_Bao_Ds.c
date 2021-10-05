/*
    Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một danh sách đặc. Mỗi sinh viên (cấu trúc SinhVien) là một phần tử trong danh sách đặc có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (float).

Khi biểu diễn bằng danh sách đặc DanhSach, người ta dùng một cấu trúc có 2 trường:

   - Mảng A chứa các sinh viên

   - Số phần tử trong danh sách: n

Hãy viết khai báo kiểu DanhSach là một danh sách đặc dùng để lưu trữ 1 danh sách sinh viên theo mô tả trên.
*/

#define Maxlength 40

typedef struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
} SinhVien;

typedef struct
{
    SinhVien A[Maxlength];
    int n;
} DanhSach;