>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một danh sách đặc. Mỗi sinh viên (cấu trúc SinhVien) là một phần tử trong danh sách đặc có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (float).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>Khi biểu diễn bằng danh sách đặc DanhSach, người ta dùng một cấu trúc có 2 trường:
>   - Mảng A chứa các sinh viên
>   - Số phần tử trong danh sách: n
##
## chenCuoi
#### Đề:
>Giả sử khai báo kiểu DanhSach đã được định nghĩa. Hãy viết 1 hàm cho phép thêm đầy đủ thông tin của 1 sinh viên (struct SinhVien) vào cuối danh sách cho trước

#### Code:
> [chenCuoi.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/chenCuoi.c)

##
## chepKhongDat
#### Đề:
>Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0
>Giả sử khai báo kiểu DanhSach đã được khai báo.  Các phép toán bên dưới cũng được định nghĩa:
>- Trả về 1 danh sách rỗng: dsRong()
>- Chèn 1 sinh viên vào cuối danh sách: chenCuoi()
>
>Hãy viết 1 hàm chép những sinh viên KHÔNG ĐẠT trong danh sách thứ nhất sang danh sách kết quả

#### Code:
> [chepKhongDat.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/chepKhongDat.c)

##
## dsRong
#### Đề:
>Giả sử khai báo kiểu DanhSach đã được định nghĩa. Hãy viết 1 hàm trả về 1 danh sách sinh viên rỗng

#### Code:
> [dsRong.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/dsRong.c)

##
## hienthi
#### Đề:
>Giả sử khai báo kiểu DanhSach đã được định nghĩa.  Hãy viết 1 hàm hiển thị danh sách sinh viên

#### Code:
> [hienthi.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/hienthi.c)

##
## hienthiDat
#### Đề:
>Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
>Giả sử khai báo kiểu DanhSach đã được định nghĩa.  Hãy viết 1 hàm hiển thị danh sách sinh viên ĐẠT.
>
#### Code:
> [hienthiDat.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/hienthiDat.c)

##
## khaibao
#### Đề:
>Hãy viết khai báo kiểu DanhSach là một danh sách đặc dùng để lưu trữ 1 danh sách sinh viên 
>
#### Code:
> [khaibao.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/khaibao.c)

##
## ktRong
#### Đề:
>Giả sử khai báo kiểu DanhSach đã được định nghĩa. Hãy viết 1 hàm kiểm tra danh sách rỗng hay không?
>
#### Code:
> [ktRong.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/ktRong.c)

##
## nhap
#### Đề:
>Giả sử khai báo kiểu DanhSach và một số các phép toán sau đã được định nghĩa:
>
>  - Thêm sinh viên s vào cuối danh sách - chenCuoi()
> - Tìm kiếm vị trí sinh viên có mã số cho trước - tim()
>  - Khởi tạo và trả về 1 danh sách rỗng - dsRong()
> 
>Hãy viết 1 hàm nhập danh sách sinh viên từ bàn phím. Chú ý nếu một mã số sinh viên đã có thì không thêm thông tin của sinh viên đó vào danh sách.

#### Code:
> [nhap.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/nhap.c)

##
## tim
#### Đề:
>Giả sử khai báo kiểu DanhSach đã được định nghĩa.  Hãy viết 1 hàm tìm vị trí sinh viên có mã số x cho trước
>
#### Code:
> [tim.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/tim.c)

##
## xoaSinhVien
#### Đề:
>Giả sử khai báo kiểu DanhSach  và các phép toán bên dưới đã được định nghĩa. 
>   - Tìm vị trí sinh viên có mã số x trong danh sách: tim()
>   - Xóa sinh viên ở vị trí p trong danh sách: xoaTai()
>
> Hãy viết 1 hàm xóa sinh viên có mã số x trong danh sách
 
#### Code:
> [xoaSinhVien.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/xoaSinhVien.c)

##
## xoaTai
#### Đề:
>Giả sử khai báo kiểu DanhSach đã được định nghĩa.  Hãy viết 1 hàm xóa sinh viên ở vị trí p trong danh sách
 
#### Code:
> [xoaTai.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Cac_phep_toan_cua_danh_sach_sinh_vien/xoaTai.c)
