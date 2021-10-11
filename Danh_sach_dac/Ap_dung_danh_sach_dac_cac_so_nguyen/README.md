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

#### Code
> [countList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_dac/Ap_dung_danh_sach_dac_cac_so_nguyen/countList.c)
