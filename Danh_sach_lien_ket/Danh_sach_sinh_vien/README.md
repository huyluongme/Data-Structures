## 
> Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp bằng một danh sách liên kết. Mỗi sinh viên (cấu trúc Student) là một phần tử trong danh sách liên kết có các thông tin: ID (chuỗi 10 ký tự), Name (chuỗi 50 ký tự), điểm thành phần R1, điểm thành phần R2, điểm thành phần R3 (các điểm này có kiểu float). 
> 
> Hình ảnh của danh sách L có dạng như bên dưới
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/Dslk.png)
## 
## Khaibaodssv
#### Đề:
> Hãy viết khai báo kiểu List là một danh sách liên kết dùng để lưu trữ 1 danh sách sinh viên theo mô tả trên.

#### Code:
> [Khaibaodssv.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/Khaibaodssv.c)
> 
## 
## append
#### Đề:
> Cho trước khai báo danh sách List và phép toán struct Node* locate(char ID[], List L) - trả về vị trí xuất hiện đầu tiên của  mã số ID trong danh sách L.
>
> Hãy viết hàm thêm một sinh viên s vào cuối danh sách cho trước.

#### Code:
> [append.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/append.c)

## 
## getFailedList
#### Đề:
> Cho trước khai báo danh sách List và các phép toán:
>
 >  - List getList() - hàm trả về một danh sách rỗng
>
 >  - struct Node* locate(char ID[], List L) - trả về vị trí xuất hiện đầu tiên của  mã số ID trong danh sách L.
>
 >  - int append(Student s, List *pL) - Nối sinh viên s vào cuối danh sách chỉ bởi con trỏ pL và trả về 1 nếu mã số sinh viên chưa có; nếu mã số đã có thì kết quả trả về của hàm là 0 mà không thêm sinh viên này vào
>
 >    - List readList(): nhập một danh sách từ bàn phím, kết quả trả về của hàm là danh sách nhập
>
 >    - void printList(List L): hiển thị danh sách sinh viên lên màn hình, mỗi SV cần hiển thị luôn điểm trung bình với điểm tb = trung bình cộng của R1, R2, R3
>
>Giả sử ta có đoạn chương trình cho phép sao chép những sinh viên KHÔNG ĐẠT (tức điểm trung bình < 4) sang danh sách kết quả
>```c
>#include<stdio.h>
>#include<malloc.h>
>#include<string.h>
>
>/*Khai báo danh sách sinh viên và một số hàm cho trước*/
>List getFailedList(List L)
>{
>	/*Duyệt qua danh sách L và sao chép những sinh viên KHÔNG ĐẠT (điểm tổng tb < 4) sang ds kết quả và trả về ds kết quả */
>	...
>}
>	
>int main()
>{
>   List L1, L2;
>        L1=readList();
>       	printList(L1);	
>        L2=getFailedList(L1);
>        printList(L2);
>        return 0;
>}
>```
>Hãy HOÀN CHỈNH CHƯƠNG TRÌNH TRÊN bằng cách điền các lệnh cần thiết vào các dấu ... để tạo thành 1 chương trình có thể thực thi được.

#### Code:
> [getFailedList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/getFailedList.c)

## 
## getList
#### Đề:
> Giả sử khai báo kiểu List đã được định nghĩa. Hãy viết 1 hàm trả về 1 danh sách sinh viên rỗng.
> 
#### Code:
> [getList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/getList.c)


## 
## locate
#### Đề:
> Cho trước khai báo danh sách List. Hãy viết hàm tìm kiếm một mã số trong danh sách cho trước.
> 
#### Code:
> [locate.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/locate.c)

## 
## printList
#### Đề:
> Cho trước khai báo danh sách List và các phép toán:
>
>   - List getList() - hàm trả về một danh sách rỗng
>
>   - struct Node* locate(char ID[], List L) - trả về vị trí xuất hiện đầu tiên của  mã số ID trong danh sách L.
>
>   - int append(Student s, List *pL) - Nối sinh viên s vào cuối danh sách chỉ bởi con trỏ pL và trả về 1 nếu mã số sinh viên chưa có; nếu mã số đã có thì kết quả trả về của hàm là 0 mà không thêm sinh viên này vào
>
>     - List readList(): nhập một danh sách từ bàn phím, kết quả trả về của hàm là danh sách nhập
>
>Giả sử ta có đoạn chương trình cho phép nhập 1 danh sách sinh viên từ bàn phím và hiển thị danh sách nhập lên màn hình
>```c
> #include<stdio.h>
> #include<malloc.h>
> #include<string.h>
>
> /*Khai báo danh sách sinh viên và một số hàm cho trước*/
> void printList(List L)
> {
>	//Duyệt qua danh sách L và hiển thị giá trị lên màn hình
>	/*Khi hiển thị thì tính luôn điểm tống hợp với điểm tổng hợp là trung bình cộng của R1, R2, R3*/
>	...
>}
>	
>int main()
>{
>	List L=readList();   
>
>        return 0;
>}
>Hãy HOÀN CHỈNH CHƯƠNG TRÌNH TRÊN bằng cách điền các lệnh cần thiết vào dấu ... để tạo thành 1 chương trình có thể thực thi được.
> 
#### Code:
> [printList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/printList.c)


## 
## readList
#### Đề:
> Cho trước khai báo danh sách List và các phép toán:
>
>   - List getList() - hàm trả về một danh sách rỗng
>
>   - struct Node* locate(char ID[], List L) - trả về vị trí xuất hiện đầu tiên của  mã số ID trong danh sách L.
>
>   - int append(Student s, List *pL) - Nối sinh viên s vào cuối danh sách chỉ bởi con trỏ pL và trả về 1 nếu mã số sinh viên chưa có; nếu mã số đã có thì kết quả trả về của hàm là 0 mà không thêm sinh viên này vào
>
> Hãy viết nhập một danh sách sinh viên từ bàn phím.
>
> Giả sử ta có đoạn chương trình cho phép nhập 1 danh sách sinh viên từ bàn phím
>```C
> #include<stdio.h>
> #include<malloc.h>
> #include<string.h>
>
>/*Khai báo danh sách sinh viên và một số hàm cho trước*/
>
> List readList()
> {
>	int n,i;
>	Student s;
>	char st[50];
>	List L = getList(); // Khởi tạo danh sách rỗng
>	scanf("%d",&n);
>	for(i=1;i<=n;i++)
>	{
>		scanf(" "); //skip some characters
>		fgets(st,10,stdin);
>		if (st[strlen(st)-1] == '\n')
>			st[strlen(st)-1] = '\0';
>		strcpy(s.ID, st);
>		fgets(st,50,stdin);
>		if (st[strlen(st)-1] == '\n')
>			st[strlen(st)-1] = '\0';
>		strcpy(s.Name, st);
>		scanf("%f%f%f",&s.R1,&s.R2,&s.R3);
>		// Nếu mã sinh viên chưa có thì chèn vào danh sách
>                ...  
>	}
>	return L;
>}    
>
>int main(){
>
>    return 0;
>}
>```
>Hãy HOÀN CHỈNH CHƯƠNG TRÌNH TRÊN bằng cách điền các lệnh cần thiết vào dấu ... (trong hàm readList()) để tạo thành 1 chương trình có thể thực thi được.

#### Code:
> [readList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/readList.c)

## 
## showPassedList
#### Đề:
> Cho trước khai báo danh sách List và các phép toán:
>
>   - List getList() - hàm trả về một danh sách rỗng
>
>   - struct Node* locate(char ID[], List L) - trả về vị trí xuất hiện đầu tiên của  mã số ID trong danh sách L.
>
>   - int append(Student s, List *pL) - Nối sinh viên s vào cuối danh sách chỉ bởi con trỏ pL và trả về 1 nếu mã số sinh viên chưa có; nếu mã số đã có thì kết quả trả về của hàm là 0 mà không thêm sinh viên này vào
>
>     - List readList(): nhập một danh sách từ bàn phím, kết quả trả về của hàm là danh sách nhập
>
>     - void printList(List L): hiển thị danh sách sinh viên lên màn hình, mỗi SV cần hiển thị luôn điểm trung bình với điểm tb = trung bình cộng của R1, R2, R3
>
> Giả sử ta có đoạn chương trình cho phép hiển thị danh sách sinh viên ĐẠT (tức điểm trung bình >= 4)
>```C
> #include<stdio.h>
> #include<malloc.h>
> #include<string.h>
>
> /*Khai báo danh sách sinh viên và một số hàm cho trước*/
> void showPassedList(List L)
> {
>	//Duyệt qua danh sách L và hiển thị những SV đạt (điểm tb >=4)
>	/*Khi hiển thị thì tính luôn điểm tống hợp với điểm tổng hợp là trung bình cộng của R1, R2, R3*/
>	...
>}
>	
> int main()
> {
>	List L=readList();
>	printList(L);       
>         showPassedList(L);
>        return 0;
> }
>```
>Hãy HOÀN CHỈNH CHƯƠNG TRÌNH TRÊN bằng cách điền các lệnh cần thiết vào dấu ... để tạo thành 1 chương trình có thể thực thi được.

#### Code:
> [showPassedList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/showPassedList.c)
