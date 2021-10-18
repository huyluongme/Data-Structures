##
# Khai báo danh sách sinh viên
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Khi biểu diễn bằng danh sách đặc **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>     - Số phần tử trong danh sách: n
>
>Hãy viết khai báo kiểu **DanhSach** là một danh sách đặc dùng để lưu trữ 1 danh sách sinh viên theo >mô tả trên.
>
>
>
>**Chú ý**
>
>- Chỉ viết khai báo, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>- Xem thêm chi tiết trong phần **For example**.
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L = {{{"B1806972","Hoang Minh", 5.5f, 4.5f, 5.0f}}, 1};
>printf("Size L = %lu x %lu\n",
>    sizeof(L.A)/sizeof(SinhVien), sizeof(SinhVien));
>printf("n = %d",L.n);
>```
></td>
><td> Size L = 40 x 72<br>n = 1 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>#define MaxLenght 40
>
>typedef struct {
>	char MSSV[10];
>	char HoTen[50];
>	float DiemLT, DiemTH1, DiemTH2;
>}SinhVien;
>
>typedef SinhVien ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType A[MaxLenght];
>	Position n;
>}DanhSach;
> ```

##
# dsRong
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Giả sử khai báo kiểu **DanhSach** đã được định nghĩa. Hãy viết 1 hàm trả về 1 danh sách sinh viên rỗng.
>
>**Nguyên mẫu**
>
>- Tên hàm: dsRong()
>- Tham số: không
>- Kiểu trả về: danh sách sinh viên
>
>**Thân hàm**
>
>- Trả về 1 danh sách rỗng
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>**Gợi ý**
>- Khai báo 1 danh sách L, cho số phần tử của danh sách này là 0
>- Trả về kết quả của hàm là L
>
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L=dsRong();
>printf("%d ",L.n);
>```
></td>
><td> 0 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>DanhSach dsRong() {
>	DanhSach L;
>	L.n = 0;
>	return L;
>}
> ```


##
# ktRong
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Giả sử khai báo kiểu **DanhSach** đã được định nghĩa. Hãy viết 1 hàm kiểm tra danh sách rỗng hay không?
>
>**Nguyên mẫu**
>
>- Tên hàm: ktRong()
>- Tham số: L: danh sách
>- Kiểu trả về: số nguyên
>
>**Thân hàm**
>
>- Nếu danh sách L rỗng, kết quả trả về là 1, ngược lại kết quả trả về là 0
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>**Gợi ý**
>- Kiểm tra số phần tử của L có bằng không hay không?
>
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L;
>L.n=0;
>printf("%d ",ktRong(L));
>```
></td>
><td> 1 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>int ktRong(DanhSach L) {
>	return L.n == 0;
>}
> ```

##
# nhap
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Giả sử khai báo kiểu **DanhSach** và một số các phép toán sau đã được định nghĩa:
>
>     - Thêm sinh viên s vào cuối danh sách - chenCuoi()
>   
>     - Tìm kiếm vị trí sinh viên có mã số cho trước - tim()
>   
>     - Khởi tạo và trả về 1 danh sách rỗng - dsRong()
>
>
>
>Hãy viết 1 hàm nhập danh sách sinh viên từ bàn phím. Chú ý nếu một mã số sinh viên đã có thì không thêm thông tin của sinh viên đó vào danh sách.
>
>**Nguyên mẫu**
>
>- Tên hàm: nhap()
>- Tham số: không
>- Kiểu trả về: danh sách
>
>**Thân hàm**
>
>- Nhập thông tin của từng sinh viên thứ i, thêm vào danh sách. Cuối cùng trả về danh sách sau khi thêm sinh viên
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>**Gợi ý**
>- Khởi tạo 1 danh sách L rỗng
>- Nhập số phần tử
>- Nhập thông tin của từng sinh viên thứ i, nếu mã số vừa đưa vào không có trong danh sách nhập trước đó thì thêm sinh viên vào cuối danh sách kết quả
>- Danh sách L là kết quả trả về của hàm
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Input </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L;
>int i;
>
>L = nhap();	
>for(i=0;i<=L.n-1;i++)
>{
>    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
>}
>```
></td>
><td> 3<br>B1804965<br>Nguyen Thai Anh<br>3 2.5 2<br>B1806421<br>Chau My Linh<br>3.25 2 2.5<br>B1804965<br>Ha Phu Dong<br>3.5 2.5 2.5 </td>
><td> B1804965 - Nguyen Thai Anh - 3.00 - 2.50 - 2.00<br>B1806421 - Chau My Linh - 3.25 - 2.00 - 2.50 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
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
> ```

##
# hienthi
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Giả sử khai báo kiểu DanhSach đã được định nghĩa.  Hãy viết 1 hàm hiển thị danh sách sinh viên
>
>**Nguyên mẫu**
>
>- Tên hàm: hienthi()
>- Tham số: 
>
>       - L: danh sách
>- 
>- Kiểu trả về: không
>
>**Thân hàm**
>
>- Hiển thị danh sách sinh viên L lên màn hình (mỗi sinh viên khi hiển thị thì tính luôn tổng điểm của sinh viên đó). 
>         Tổng điểm = Điểm lý thuyết + Điểm thực hành 1 + Điểm thực hành 2
>
>- Xem ví dụ để biết chi tiết về việc hiển thị
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
>struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
>L.A[1] = s;
>L.n++;
>hienthi(L);
>```
></td>
><td> B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00 - 9.50<br>B1806973 - Thai Anh - 4.50 - 1.25 - 1.00 - 6.75<br> </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void hienthi(DanhSach L) {
>	for (int i = 1; i < L.n + 1; i++)
>		printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2, L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2);
>}
> ```


##
# hienthiDat
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
>
>Giả sử khai báo kiểu **DanhSach** đã được định nghĩa.  Hãy viết 1 hàm hiển thị danh sách sinh viên ĐẠT.
>
>**Nguyên mẫu**
>
>- Tên hàm: hienthiDat()
>- Tham số: 
>
>       - L: danh sách
>- 
>- Kiểu trả về: không
>
>**Thân hàm**
>
>- Hiển thị danh sách sinh viên ĐẠT lên màn hình (mỗi sinh viên khi hiển thị thì tính luôn tổng điểm của sinh viên đó). 
>
>- Xem ví dụ để biết chi tiết về việc hiển thị
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
>struct SinhVien s1 = {"B1806872","Minh Dong", 1.5f, 1.0f, 1.0f}; 
>struct SinhVien s2 = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
>L.A[1] = s1;
>L.n++;
>L.A[2] = s2;
>L.n++;
>hienthiDat(L);
>```
></td>
><td> B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00 - 9.50<br>B1806973 - Thai Anh - 4.50 - 1.25 - 1.00 - 6.75 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void hienthiDat(DanhSach L) {
>	for (int i = 1; i < L.n + 1; i++)
>		if (L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2 >= 4.0)
>			printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i - 1].MSSV, L.A[i - 1].HoTen, L.A[i - 1].DiemLT, L.A[i - 1].DiemTH1, L.A[i - 1].DiemTH2, L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2);
>}
> ```


##
# tim
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Giả sử khai báo kiểu **DanhSach** đã được định nghĩa.  Hãy viết 1 hàm tìm vị trí sinh viên có mã số x cho trước
>
>**Nguyên mẫu**
>
>- Tên hàm: tim()
>- Tham số: 
>
>       - x: chuỗi 10 ký tự
>       - L: danh sách
>- 
>- Kiểu trả về: không
>
>**Thân hàm**
>
>- Trả về vị trí của sinh viên đầu tiên có mã số x trong danh sách nếu tìm thấy, nếu không thấy kết quả trả về là (số phần tử trong danh sách +1)
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>**Gợi ý**
>- Tìm kiếm tuần tự trong danh sách L
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
>struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
>int p,i;
>L.A[1] = s;
>L.n++;
>for(i=0;i<L.n;i++)
>{
>    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
>}
>
>p = tim("B1806973", L);
>if (p > L.n)
>  printf("Tim khong thay");
>else printf("Tim thay o vi tri %d",p);
>```
></td>
><td> B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00<br>B1806973 - Thai Anh - 4.50 - 1.25 - 1.00 <br>Tim thay o vi tri 2 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
>struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
>int p,i;
>L.A[1] = s;
>L.n++;
>for(i=0;i<L.n;i++)
>{
>    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
>}
>
>p = tim("B1806979", L);
>if (p > L.n)
>  printf("Tim khong thay p = %d",p);
>else printf("Tim thay o vi tri %d",p);
>```
></td>
><td> B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00<br>B1806973 - Thai Anh - 4.50 - 1.25 - 1.00 <br>Tim khong thay p = 3 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
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
> ```


##
# xoaTai
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Giả sử khai báo kiểu **DanhSach** đã được định nghĩa.  Hãy viết 1 hàm xóa sinh viên ở vị trí p trong danh sách
>
>**Nguyên mẫu**
>
>- Tên hàm: xoaTai()
>- Tham số: 
>
>       - p: số nguyên
>       - pL: con trỏ danh sách
>- 
>- Kiểu trả về: số nguyên
>
>**Thân hàm**
>
>- Nếu p là vị trí hợp lệ thì xóa sinh viên ở vị trí p trong danh sách chỉ bởi con trỏ pL
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L = {{{"B1806972","Hoang Minh", 5.5f, 2.5f, 2.0f}}, 1};
>struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
>int i;
>L.A[1] = s;
>L.n++;
>for(i=0;i<L.n;i++)
>{
>    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
>}
>xoaTai(1, &L);
>printf("\n");
>for(i=0;i<L.n;i++)
>{
>    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
>}
>```
></td>
><td> B1806972 - Hoang Minh - 5.50 - 2.50 - 2.00<br>B1806973 - Thai Anh - 4.50 - 1.25 - 1.00<br><br>B1806973 - Thai Anh - 4.50 - 1.25 - 1.00 <br> </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>int xoaTai(int p, DanhSach* pL) {
>	if (p < 1 || p > pL->n)
>		return 0;
>	else {
>		for (int i = 1; i < pL->n + 1; i++)
>			pL->A[i - 1] = pL->A[i];
>		pL->n--;
>		return 1;
>	}
>}
> ```


##
# chenCuoi
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Giả sử khai báo kiểu **DanhSach** đã được định nghĩa. Hãy viết 1 hàm cho phép thêm đầy đủ thông tin của 1 sinh viên (struct SinhVien) vào cuối danh sách cho trước
>
>**Nguyên mẫu**
>
>- Tên hàm: chenCuoi()
>- Tham số: 
>
>       - s: struct SinhVien
>       - pL: con trỏ danh sách
>- 
>- Kiểu trả về: không
>
>**Thân hàm**
>
>- Thêm s vào cuối danh sách chỉ bởi con trỏ pL nếu còn có thể thêm được
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>**Gợi ý**
>- Nếu còn có thể thêm được thì đưa s vào chỉ số n trong mảng A của danh sách; sau đó tăng số phần tử lên 1
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
>struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
>int i;
>chenCuoi(s, &L);
>for(i=0;i<L.n;i++)
>{
>    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
>}
>```
></td>
><td> B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00<br>B1806973 - Thai Anh - 4.50 - 1.25 - 1.00 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>DanhSach L;
>L.n=40;
>struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 2.0f}; 
>chenCuoi(s, &L);
>```
></td>
><td> Loi! Danh sach day! </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void chenCuoi(struct SinhVien s, DanhSach* pL) {
>	if (pL->n == 40)
>		printf("Loi! Danh sach day!");
>	else {
>		pL->A[pL->n] = s;
>		pL->n++;
>	}
>}
> ```


##
# chepKhongDat
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
>
>Giả sử khai báo kiểu **DanhSach** đã được khai báo.  Các phép toán bên dưới cũng được định nghĩa:
>
>     - Trả về 1 danh sách rỗng: **dsRong()**
>   
>     - Chèn 1 sinh viên vào cuối danh sách: **chenCuoi()**
>
>
>
>Hãy viết 1 hàm chép những sinh viên KHÔNG ĐẠT trong danh sách thứ nhất sang danh sách kết quả
>
>**Nguyên mẫu**
>
>- Tên hàm: chenCuoi()
>- Tham số: 
>
>       - L: danh sách vào
>- 
>- Kiểu trả về: danh sách kết quả chứa những sinh viên KHÔNG ĐẠT
>
>**Thân hàm**
>
>- Chép những sinh viên có điểm < 4 sang danh sách kết quả
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>**Gợi ý**
>- Khởi tạo danh sách kết quả rỗng
>- Duyệt qua danh sách đầu vào, với từng sinh viên trong danh sách vào này, nếu tổng điểm của sinh viên đó <4.0 thì chèn sinh viên đó vào danh sách kết quả
>- Trả về danh sách kết quả 
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>int i;
>DanhSach L1;
>DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
>struct SinhVien s1 = {"B1806872","Minh Dong", 1.5f, 1.0f, 1.0f}; 
>struct SinhVien s2 = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
>struct SinhVien s3 = {"B1818973","Dong Nghi", 0.5f, 1.25f, 1.0f}; 
>L.A[1] = s1;
>L.n++;
>L.A[2] = s2;
>L.n++;
>L.A[3] = s3;
>L.n++;
>L1 = chepKhongDat(L);
>printf("Khong dat:\n");
>for(i=0;i<=L1.n-1;i++)
>{
>    printf("%s - %s - %.2f - %.2f - %.2f\n",L1.A[i].MSSV, L1.A[i].HoTen, L1.A[i].DiemLT, L1.A[i].DiemTH1, L1.A[i].DiemTH2);
>}
>```
></td>
><td> Khong dat:<br>B1806872 - Minh Dong - 1.50 - 1.00 - 1.00<br>B1818973 - Dong Nghi - 0.50 - 1.25 - 1.00 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>DanhSach chepKhongDat(DanhSach L) {
>	DanhSach result = dsRong();
>	for (int i = 1; i < L.n + 1; i++)
>		if (L.A[i - 1].DiemLT + L.A[i - 1].DiemTH1 + L.A[i - 1].DiemTH2 < 4.0)
>			chenCuoi(L.A[i - 1], &result);
>	return result;
>}
> ```

##
# xoaSinhVien
>Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf). Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).
>
>Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
>```c
>struct SinhVien{
>   char MSSV[10];
>   char HoTen[50];
>   float DiemLT, DiemTH1, DiemTH2;
>};
>```
>
>Khi biểu diễn bằng [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) **DanhSach**, người ta dùng một cấu trúc có 2 trường:
>
>     - Mảng A chứa các sinh viên
>  
>     - Số phần tử trong danh sách: n
>
>
>
>Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.
>
>Giả sử khai báo kiểu DanhSach  và các phép toán bên dưới đã được định nghĩa. 
>
>     - Tìm vị trí sinh viên có mã số x trong danh sách: tim()
>  
>     - Xóa sinh viên ở vị trí p trong danh sách: xoaTai()
>
> Hãy viết 1 hàm xóa sinh viên có mã số x trong danh sách
>
>**Nguyên mẫu**
>
>- Tên hàm: xoaSinhVien()
>- Tham số: 
>
>       - x chuỗi lưu mã số SV
>
>       - pL: con trỏ danh sách
>- 
>- Kiểu trả về: không
>
>**Thân hàm**
>
>- Gọi p là vị trí của sinh viên có mã số x trong danh sách; nếu p là vị trí hợp lệ thì xóa sinh viên ở vị trí p trong danh sách chỉ bởi con trỏ pL
>
>
>**Chú ý**
>- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>**For example:**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
>struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
>int i;
>L.A[1] = s;
>L.n++;
>for(i=0;i<L.n;i++)
>{
>    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
>}
>xoaSinhVien("B1806973", &L);
>printf("\n");
>for(i=0;i<L.n;i++)
>{
>    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
>}
>```
></td>
><td> B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00<br>B1806973 - Thai Anh - 4.50 - 1.25 - 1.00<br><br>B1806972 - Hoang Minh - 5.00 - 2.50 - 2.00 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void xoaSinhVien(char x[], DanhSach* pL) {
>	int p = tim(x, *pL);
>	if (p != pL->n + 1)
>		xoaTai(p, pL);
>}
> ```
