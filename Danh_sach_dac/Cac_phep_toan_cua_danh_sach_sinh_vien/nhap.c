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



Giả sử khai báo kiểu DanhSach và một số các phép toán sau đã được định nghĩa:

  - Thêm sinh viên s vào cuối danh sách - chenCuoi()

  - Tìm kiếm vị trí sinh viên có mã số cho trước - tim()

  - Khởi tạo và trả về 1 danh sách rỗng - dsRong()



Hãy viết 1 hàm nhập danh sách sinh viên từ bàn phím. Chú ý nếu một mã số sinh viên đã có thì không thêm thông tin của sinh viên đó vào danh sách.
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

int tim(char x[], DanhSach L)
{
    for (int i = 1; i <= L.n; i++)
    {
        if (strcmp(L.A[i - 1].MSSV, x) == 0)
            return i;
    }
    return L.n + 1;
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

DanhSach nhap()
{
    DanhSach L = dsRong();
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        struct SinhVien temp;
        fgets(temp.MSSV, 10, stdin);
		if (temp.MSSV[strlen(temp.MSSV) - 1] == '\n')
			temp.MSSV[strlen(temp.MSSV) - 1] = '\0';

		fgets(temp.HoTen, 50, stdin);
		if (temp.HoTen[strlen(temp.HoTen) - 1] == '\n')
			temp.HoTen[strlen(temp.HoTen) - 1] = '\0';

		scanf("%f%f%f", &temp.DiemLT, &temp.DiemTH1, &temp.DiemTH2);
		getchar();
        if(tim(temp.MSSV,L) > L.n){
            chenCuoi(temp, &L);
        }
    }

    return L;
}

int main()
{
    DanhSach L;
int i;

L = nhap();	
for(i=0;i<=L.n-1;i++)
{
    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
}
    return 0;
}