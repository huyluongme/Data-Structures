> Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một danh sách đặc. Mỗi sinh viên (cấu trúc SinhVien) là một phần tử trong danh sách đặc có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (float).
> Khi biểu diễn bằng danh sách đặc DanhSach, người ta dùng một cấu trúc có 2 trường:
>    - Mảng A chứa các sinh viên
>   - Số phần tử trong danh sách: n
>```c
>#define MaxLenght 40
>
>struct SinhVien {
>	char MSSV[10];
>	char HoTen[50];
>	float DiemLT, DiemTH1, DiemTH2;
>};
>
>typedef struct SinhVien ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType A[MaxLenght];
>	Position n;
>}DanhSach;
>```
## 
## liet_ke_DAT
#### Đề:
> Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
> Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên. Sau đó liệt kê những sinh viên KHÔNG ĐẠT.

#### Code:
> [liet_ke_DAT.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Goi_thuc_thi_cac_phep_toan_cua_danh_sach_sinh_vien/liet_ke_DAT.c)

## 
## liet_ke_khong_DAT
#### Đề:
> Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
> Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên. Sau đó liệt kê những sinh viên KHÔNG ĐẠT.

#### Code:
> [liet_ke_khong_DAT.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Goi_thuc_thi_cac_phep_toan_cua_danh_sach_sinh_vien/liet_ke_khong_DAT.c)

## 
## nhap&hienthi_ds_sinh_vien
#### Đề:
> Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên.

#### Code:
> [nhap&hienthi_ds_sinh_vien.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Goi_thuc_thi_cac_phep_toan_cua_danh_sach_sinh_vien/nhap&hienthi_ds_sinh_vien.c)

## 
## tim_kiem_sinh_vien
#### Đề:
> Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên. Sau đó nhập một mã số sinh viên từ bàn phím, nếu mã số tồn tại thì xóa sinh viên có mã số đó.
>
#### Code:
> [tim_kiem_sinh_vien.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Goi_thuc_thi_cac_phep_toan_cua_danh_sach_sinh_vien/tim_kiem_sinh_vien.c)
