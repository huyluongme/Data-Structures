##
# Liệt kê sinh viên ĐẠT
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>
>
>Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
>
>
>Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên. Sau đó liệt kê những sinh viên ĐẠT.
>
>
>**Gợi ý**
>
>- Khai báo kiểu DanhSach
>- Định nghĩa các hàm nhập và hiển thị danh sách sinh viên
>- Định nghĩa hàm liệt kê sinh viên ĐẠT
>- Gọi thực thi các hàm trên trong hàm main()
>
> **For example**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td>2<br>B1804965<br>Nguyen Thai Anh<br>3 2.5 2<br>B1806421<br>Chau My Linh<br>3.25 2 2.5</td>
><td> B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50<br>Sinh vien DAT<br>B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50 </td>
></tr>
><tr>
></tr>
><tr>
><td> 3<br>B1804965<br>Nguyen Thai Anh<br>3 2.5 2<br>B1806421<br>Chau My Linh<br>1.25 1 1.5<br>B1804911<br>Ha Phu Dong<br>3.5 2.5 2.5<br>B1804911 </td>
><td> B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 1.25 - 1.00 - 1.50<br>B1804911 - Ha Phu Dong - 3.50 - 2.50 - 2.50<br>Sinh vien DAT<br>B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1804911 - Ha Phu Dong - 3.50 - 2.50 - 2.50 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>#include <stdio.h>
>#include <string.h>
>
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
>
>DanhSach dsRong() {
>	DanhSach L;
>	L.n = 0;
>	return L;
>}
>
>int tim(char x[], DanhSach L) {
>	int i = 1;
>	while (i != L.n + 1) {
>		if (strcmp(x, L.A[i - 1].MSSV) == 0)
>			return i;
>		else
>			i++;
>	}
>	return i;
>}
>
>void chenCuoi(struct SinhVien s, DanhSach* pL) {
>	if (pL->n == 40)
>		printf("Loi! Danh sach day!");
>	else {
>		pL->A[pL->n] = s;
>		pL->n++;
>	}
>}
>
>DanhSach nhap() {
>	DanhSach L = dsRong();
>	int n;
>	scanf("%d%*c", &n);
>	for (int i = 0; i < n; i++) {
>		struct SinhVien s;
>
>		fgets(s.MSSV, 10, stdin);
>		if (s.MSSV[strlen(s.MSSV) - 1] == '\n')
>			s.MSSV[strlen(s.MSSV) - 1] = '\0';
>
>		fgets(s.HoTen, 50, stdin);
>		if (s.HoTen[strlen(s.HoTen) - 1] == '\n')
>			s.HoTen[strlen(s.HoTen) - 1] = '\0';
>
>		scanf("%f%f%f%*c", &s.DiemLT, &s.DiemTH1, &s.DiemTH2);
>
>		if (tim(s.MSSV, L) == L.n + 1)
>			chenCuoi(s, &L);
>	}
>	return L;
>}
>
>void hienthi(DanhSach L) {
>	for (int i = 1; i < L.n + 1; i++)
>		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
>}
>
>void hienthiDat(DanhSach L) {
>	for (int i = 1; i < L.n + 1; i++)
>		if (L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2 >= 4.0)
>			printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
>}
>
>int main() {
>	DanhSach L = nhap();
>	hienthi(L);
>	printf("Sinh vien DAT\n");
>	hienthiDat(L);
>	return 0;
>}
> ```

##
# Tìm sinh viên
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>
>
>Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
>
>
>Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên. Sau đó nhập một mã số sinh viên từ bàn phím, nếu mã số tồn tại thì xóa sinh viên có mã số đó.
>
>
>**Gợi ý**
>
>- Khai báo kiểu DanhSach
>- Định nghĩa các hàm nhập và hiển thị danh sách sinh viên
>- Định nghĩa hàm tìm kiếm sinh viên có mã số cho trước
>- Định nghĩa hàm xóa sinh viên có mã số cho trước
>- Gọi thực thi các hàm trên trong hàm main()
>
> **For example**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 2<br>B1804965<br>Nguyen Thai Anh<br>3 2.5 2<br>B1806421<br>Chau My Linh<br>3.25 2 2.5<br>B1804965 </td>
><td>B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50<br>Tim thay sinh vien B1804965. Thong tin sinh vien:<br>B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00 </td>
></tr>
><tr>
></tr>
><tr>
><td> 3<br>B1804965<br>Nguyen Thai Anh<br>3 2.5 2<br>B1806421<br>Chau My Linh<br>3.25 2 2.5<br>B1804911<br>Ha Phu Dong<br>3.5 2.5 2.5<br>B1804912 </td>
><td> B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50<br>B1804911 - Ha Phu Dong - 3.50 - 2.50 - 2.50<br>Khong tim thay sinh vien B1804912 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>#include <stdio.h>
>#include <string.h>
>
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
>
>DanhSach dsRong() {
>	DanhSach L;
>	L.n = 0;
>	return L;
>}
>
>void chenCuoi(struct SinhVien s, DanhSach* pL) {
>	if (pL->n == 40)
>		printf("Loi! Danh sach day!");
>	else {
>		pL->A[pL->n] = s;
>		pL->n++;
>	}
>}
>
>int tim(char x[], DanhSach L) {
>	int i = 1;
>	while (i != L.n + 1) {
>		if (strcmp(x, L.A[i - 1].MSSV) == 0)
>			return i;
>		else
>			i++;
>	}
>	return i;
>}
>
>DanhSach nhap() {
>	DanhSach L = dsRong();
>	int n;
>	scanf("%d%*c", &n);
>	for (int i = 0; i < n; i++) {
>		struct SinhVien s;
>
>		fgets(s.MSSV, 10, stdin);
>		if (s.MSSV[strlen(s.MSSV) - 1] == '\n')
>			s.MSSV[strlen(s.MSSV) - 1] = '\0';
>
>		fgets(s.HoTen, 50, stdin);
>		if (s.HoTen[strlen(s.HoTen) - 1] == '\n')
>			s.HoTen[strlen(s.HoTen) - 1] = '\0';
>
>		scanf("%f%f%f%*c", &s.DiemLT, &s.DiemTH1, &s.DiemTH2);
>
>		if (tim(s.MSSV, L) == L.n + 1)
>			chenCuoi(s, &L);
>	}
>	return L;
>}
>
>void hienthi(DanhSach L) {
>	for (int i = 1; i < L.n + 1; i++)
>		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
>}
>
>int main() {
>	DanhSach L = nhap();
>	char x[10];
>	fgets(x, 10, stdin);
>	if (x[strlen(x) - 1] == '\n')
>		x[strlen(x) - 1] = '\0';
>	hienthi(L);
>	int p = tim(x, L);
>	if (p != L.n + 1)
>		printf("Tim thay sinh vien %s. Thong tin sinh vien:\n%s - %s - %.2f - %.2f - %.2f", x, L.A[p - 1].MSSV, L.A[p - 1].HoTen, L.A[p - 1].DiemLT, L.A[p - 1].DiemTH1, L.A[p - 1].DiemTH2);
>	else
>		printf("Khong tim thay sinh vien %s", x);
>	return 0;
>}
> ```


##
# Nhập và hiển thị danh sách sinh viên
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>
>
>Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
>
>
>Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên.
>
>
>**Gợi ý**
>
>- Khai báo kiểu DanhSach
>- Định nghĩa các hàm nhập và hiển thị danh sách sinh viên
>- Gọi thực thi hàm nhập và hiển thị trong hàm main()
>
> **For example**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 2<br>B1804965<br>Nguyen Thai Anh<br>3 2.5 2<br>B1806421<br>Chau My Linh<br>3.25 2 2.5 </td>
><td>B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50 </td>
></tr>
><tr>
></tr>
><tr>
><td> 3<br>B1804965<br>Nguyen Thai Anh<br>3 2.5 2<br>B1806421<br>Chau My Linh<br>3.25 2 2.5<br>B1804911<br>Ha Phu Dong<br>3.5 2.5 2.5 </td>
><td> B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50<br>B1804911 - Ha Phu Dong - 3.50 - 2.50 - 2.50 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>#include <stdio.h>
>#include <string.h>
>
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
>
>DanhSach dsRong() {
>	DanhSach L;
>	L.n = 0;
>	return L;
>}
>
>void chenCuoi(struct SinhVien s, DanhSach* pL) {
>	if (pL->n == 40)
>		printf("Loi! Danh sach day!");
>	else {
>		pL->A[pL->n] = s;
>		pL->n++;
>	}
>}
>
>int tim(char x[], DanhSach L) {
>	int i = 1;
>	while (i != L.n + 1) {
>		if (strcmp(x, L.A[i - 1].MSSV) == 0)
>			return i;
>		else
>			i++;
>	}
>	return i;
>}
>
>DanhSach nhap() {
>	DanhSach L = dsRong();
>	int n;
>	scanf("%d%*c", &n);
>	for (int i = 0; i < n; i++) {
>		struct SinhVien s;
>
>		fgets(s.MSSV, 10, stdin);
>		if (s.MSSV[strlen(s.MSSV) - 1] == '\n')
>			s.MSSV[strlen(s.MSSV) - 1] = '\0';
>
>		fgets(s.HoTen, 50, stdin);
>		if (s.HoTen[strlen(s.HoTen) - 1] == '\n')
>			s.HoTen[strlen(s.HoTen) - 1] = '\0';
>
>		scanf("%f%f%f%*c", &s.DiemLT, &s.DiemTH1, &s.DiemTH2);
>
>		if (tim(s.MSSV, L) == L.n + 1)
>			chenCuoi(s, &L);
>	}
>	return L;
>}
>
>void hienthi(DanhSach L) {
>	for (int i = 1; i < L.n + 1; i++)
>		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
>}
>
>int main() {
>	DanhSach L = nhap();
>	hienthi(L);
>	return 0;
>}
> ```

##
# Liệt kê sinh viên KHÔNG ĐẠT
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>
>
>Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
>
>
>Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên. Sau đó liệt kê những sinh viên KHÔNG ĐẠT.
>
>
>**Gợi ý**
>
>- Khai báo kiểu DanhSach
>- Định nghĩa các hàm nhập và hiển thị danh sách sinh viên
>- Định nghĩa hàm chép những sinh viên không đạt sang danh sách kết quả
>- Gọi thực thi các hàm trên trong hàm main()
>
> **For example**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 2<br>B1804965<br>Nguyen Thai Anh<br>3 2.5 2<br>B1806421<br>Chau My Linh<br>1.25 1 1.5 </td>
><td> B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 1.25 - 1.00 - 1.50<br>Sinh vien KHONG DAT<br>B1806421 - Chau My Linh - 1.25 - 1.00 - 1.50 </td>
></tr>
><tr>
></tr>
><tr>
><td> 3<br>B1804965<br>Nguyen Thai Anh<br>3 2.5 2<br>B1806421<br>Chau My Linh<br>1.25 1 1.5<br>B1804911<br>Ha Phu Dong<br>0.5 0.5 2.5 </td>
><td> B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 1.25 - 1.00 - 1.50<br>B1804911 - Ha Phu Dong - 0.50 - 0.50 - 2.50<br>Sinh vien KHONG DAT<br>B1806421 - Chau My Linh - 1.25 - 1.00 - 1.50<br>B1804911 - Ha Phu Dong - 0.50 - 0.50 - 2.50 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>#include <stdio.h>
>#include <string.h>
>
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
>
>DanhSach dsRong() {
>	DanhSach L;
>	L.n = 0;
>	return L;
>}
>
>void chenCuoi(struct SinhVien s, DanhSach* pL) {
>	if (pL->n == 40)
>		printf("Loi! Danh sach day!");
>	else {
>		pL->A[pL->n] = s;
>		pL->n++;
>	}
>}
>
>DanhSach chepKhongDat(DanhSach L) {
>	DanhSach result = dsRong();
>	for (int i = 1; i < L.n + 1; i++)
>		if (L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2 < 4.0)
>			chenCuoi(L.A[i - 1], &result);
>	return result;
>}
>
>int tim(char x[], DanhSach L) {
>	int i = 1;
>	while (i != L.n + 1) {
>		if (strcmp(x, L.A[i - 1].MSSV) == 0)
>			return i;
>		else
>			i++;
>	}
>	return i;
>}
>
>DanhSach nhap() {
>	DanhSach L = dsRong();
>	int n;
>	scanf("%d%*c", &n);
>	for (int i = 0; i < n; i++) {
>		struct SinhVien s;
>
>		fgets(s.MSSV, 10, stdin);
>		if (s.MSSV[strlen(s.MSSV) - 1] == '\n')
>			s.MSSV[strlen(s.MSSV) - 1] = '\0';
>
>		fgets(s.HoTen, 50, stdin);
>		if (s.HoTen[strlen(s.HoTen) - 1] == '\n')
>			s.HoTen[strlen(s.HoTen) - 1] = '\0';
>
>		scanf("%f%f%f%*c", &s.DiemLT, &s.DiemTH1, &s.DiemTH2);
>
>		if (tim(s.MSSV, L) == L.n + 1)
>			chenCuoi(s, &L);
>	}
>	return L;
>}
>
>void hienthi(DanhSach L) {
>	for (int i = 1; i < L.n + 1; i++)
>		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].>DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2);
>}
>
>int main() {
>	DanhSach L = nhap();
>	hienthi(L);
>	DanhSach L2 = chepKhongDat(L);
>	printf("Sinh vien KHONG DAT\n");
>	hienthi(L2);
>	return 0;
>}
> ```