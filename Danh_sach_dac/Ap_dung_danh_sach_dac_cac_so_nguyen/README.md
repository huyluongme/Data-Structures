## countList
#### Đề:
> Để cài đặt cấu trúc danh sách đặc với kiểu phần tử là số nguyên, cho trước các khai báo như sau:
>```c
>#define MaxLenght 50
>
>typedef int ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType Elements[MaxLenght];
>	Position Last;
>}List;
>```
>Các phép toán cơ bản trên danh sách cũng đã được cài đặt
>```c
>void makenullList(List *L)
>int emptyList(List L)
>Position first(List L)
>Position endList(List L)
>Position next(Position P, List L)
>ElementType retrieve(Position P, List L)
>void insertList(ElementType X, Position P, List *L)
>void deleteList(Position P, List *L)
>void readList(int n,List *L)
>void printList(List L)
>Position locate(ElementType X,List L)
>```
>Hãy viết hàm
>```
>int countList(ElementType X, List L)
>```
> đếm số lần xuất hiện của X trong danh sách L

#### Code
> [countList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/countList.c)

## deleteAll
#### Đề:
> Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép xóa tất cả các phần tử x trong danh sách

#### Code:
> [deleteAll.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/deleteAll.c)

## deleteX
#### Đề:
> Bằng cách sử dụng những phép toán chuẩn trên danh sách đã cho trong thư viện AListLib.c, hãy viết chương trình nhập một danh sách từ bàn phím và cho phép xóa phần tử x xuất hiện đầu tiên trong danh sách

#### Code
> [deleteX.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/deleteX.c)

## difference
#### Đề:
> Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép tìm hiệu của 2 danh sách biểu diễn tập hợp

#### Code
> [difference.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/difference.c)

## getAVG
#### Đề:
> Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép tính trung bình cộng các phần tử trong danh sách

#### Code
> [getAVG.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/getAVG.c)

## intersection
#### Đề:
> Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép tìm tập hợp giao của 2 danh sách biểu diễn tập hợp

#### Code
> [intersection.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/intersection.c)

## maxList
#### Đề:
> Để cài đặt cấu trúc danh sách đặc với kiểu phần tử là số nguyên, cho trước các khai báo như sau:
>```c
>#define MaxLenght 50
>
>typedef int ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType Elements[MaxLenght];
>	Position Last;
>}List;
>```
>Các phép toán cơ bản trên danh sách cũng đã được cài đặt
>```c
>void makenullList(List *L)
>int emptyList(List L)
>Position first(List L)
>Position endList(List L)
>Position next(Position P, List L)
>ElementType retrieve(Position P, List L)
>void insertList(ElementType X, Position P, List *L)
>void deleteList(Position P, List *L)
>void readList(int n,List *L)
>void printList(List L)
>Position locate(ElementType X,List L)
>```
>Hãy viết hàm
>```
>ElementType maxList(List L)
>```
>trả về giá trị lớn nhất trong các phần tử của danh sách L

#### Code
> [maxList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/maxList.c)

## minList
#### Đề:
> Để cài đặt cấu trúc danh sách đặc với kiểu phần tử là số nguyên, cho trước các khai báo như sau:
>```c
>#define MaxLenght 50
>
>typedef int ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType Elements[MaxLenght];
>	Position Last;
>}List;
>```
>Các phép toán cơ bản trên danh sách cũng đã được cài đặt
>```c
>void makenullList(List *L)
>int emptyList(List L)
>Position first(List L)
>Position endList(List L)
>Position next(Position P, List L)
>ElementType retrieve(Position P, List L)
>void insertList(ElementType X, Position P, List *L)
>void deleteList(Position P, List *L)
>void readList(int n,List *L)
>void printList(List L)
>Position locate(ElementType X,List L)
>```
>Hãy viết hàm
>```
>ElementType minList(List L)
>```
>trả về giá trị nhỏ nhất trong các phần tử của danh sách L

#### Code
> [minList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/minList.c)

## nhap&hienthi_danh_sach_tu_ban_phim
#### Đề:
> Cho trước khai báo kiểu List như trên cùng với các phép toán:
>
>- void readList(List *pL): Nhập một danh sách chỉ bởi con trỏ pL từ bàn phím
>- void printList(List L): hiển thị danh sách L lên màn hình
>
>Và cho hàm main() như sau:
>```c
>#include <stdio.h>
>
>int main(){
>    //Khai báo biến
>    List L;
>
>    //Gọi hàm nhập và hàm hiển thị danh sách
>    ...
>
>    return 0;
>}
>```
>Hãy hoàn chỉnh chương trình trên bằng cách điền các lệnh cần thiết vào dấu ...  để tạo thành 1 chương trình cho phép nhập và hiển thị 1 danh sách từ bàn phím

#### Code
> [nhap&hienthi_danh_sach_tu_ban_phim.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/nhap&hienthi_danh_sach_tu_ban_phim.c)

## printEvenNum_AVGofEvenNum
#### Đề:
> Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép liệt kê các số chẵn và tính trung bình cộng các phần tử là số chẵn trong danh sách

#### Code
> [printEvenNum_AVGofEvenNum.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/printEvenNum_AVGofEvenNum.c)

## printOddEvenNumbers
#### Đề:
> Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép liệt kê các số lẻ, số chẵn trong danh sách

#### Code
> [printOddEvenNumbers.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/printOddEvenNumbers.c)

## sort
#### Đề:
> Bằng cách sử dụng những phép toán chuẩn trên danh sách đã cho trong thư viện AListLib.c, hãy viết chương trình cho phép sắp xếp danh sách tăng dần

#### Code
> [sort.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/sort.c)

## sumList
#### Đề:
> Để cài đặt cấu trúc danh sách đặc với kiểu phần tử là số nguyên, cho trước các khai báo như sau:
>```c
>#define MaxLenght 50
>
>typedef int ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType Elements[MaxLenght];
>	Position Last;
>}List;
>```
>Các phép toán cơ bản trên danh sách cũng đã được cài đặt
>```c
>void makenullList(List *L)
>int emptyList(List L)
>Position first(List L)
>Position endList(List L)
>Position next(Position P, List L)
>ElementType retrieve(Position P, List L)
>void insertList(ElementType X, Position P, List *L)
>void deleteList(Position P, List *L)
>void readList(int n,List *L)
>void printList(List L)
>Position locate(ElementType X,List L)
>```
>Hãy viết hàm
>```
>int sumList(ElementType X, List L)
>```
> trả về tổng giá trị các phần tử trong danh sách L

#### Code
> [sumList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/sumList.c)

## unionSet
#### Đề:
> Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép tìm tập hợp hợp của 2 danh sách biểu diễn tập hợp

#### Code
> [unionSet.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/unionSet.c)
