## 
## addFirst
#### Đề:
>Giả sử kiểu dữ liệu List đã được khai báo. 
>
>Viết hàm cho phép chèn phần tử x vào đầu danh sách.
>
>Chẳng hạn danh sách L = [1, 5, 10]
>
>                           addFirst(-10, &L)
>                           
>           Kết quả L = [-10, 1, 5, 10]

#### Code:
>[addFirst.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/addFirst.c)

## 
## append
#### Đề:
>Giả sử kiểu dữ liệu List đã được khai báo. 
>
>Viết hàm cho phép nối phần tử x vào trong danh sách.
>
>Chẳng hạn danh sách L = [1, 5, 10]
>
>                          append(-10, &L)
>
>           Kết quả L = [1, 5, 10, -10]

#### Code:
>[append.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/append.c)

## 
## copyEvenNumbers
#### Đề:
>Cho trước các phép toán sau:
>
> - Khởi tạo danh sách rỗng makenullList()
> 
> - Nối phần tử x vào danh sách append()
>
>Hãy viết hàm chép toàn bộ các số chẵn trong danh sách L1 sang danh sách kết quả.

#### Code:
>[copyEvenNumbers.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/copyEvenNumbers.c)

## 
## deleteList
#### Đề:
>Viết hàm cho phép xóa phần tử ở vị trí p trong danh sách

#### Code:
>[deleteList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/deleteList.c)

## 
## deleteX
#### Đề:
>Để cài đặt cấu trúc danh sách liên kết với kiểu phần tử là số nguyên, cho trước các khai báo như sau:
>
>```c
>typedef int ElementType;
>
>struct Node{
>ElementType Element;
>struct Node* Next;
>};
>
>typedef struct Node*    Position;
>typedef Position List;
>```
>
>Các phép toán cơ bản cũng đã được cài đặt
>```
>void makenullList(List *pL)
>Position first(List L)
>Position endList (List L)
>Position next ( Position P, List L)
>ElementType retrieve(Position P, List L)
>void insertList(ElementType X, Position P, List *pL)
>void deleteList(Position P, List *pL)
>```
>Hãy viết hàm
>
>```c
>void deleteX(ElementType X, List *pL)
>```
>xóa tất cả phần tử có giá trị bằng X trong danh sách L. Hàm deleteX tái sử dụng dụng một số phép toán cơ bản đã được cài đặt.

#### Code:
>[deleteX.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/deleteX.c)

## 
## difference
#### Đề:
>Cho trước các phép toán sau:
>
> - Khởi tạo danh sách rỗng makenullList()
>- Kiểm tra phần tử X có trong danh sách hay không member()
>- Nối phần tử x vào danh sách append()
>
>Hãy viết hàm tìm tập hơp hiệu của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2.

#### Code:
>[difference.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/difference.c)


## 
## erase
#### Đề:
>Cho trước các phép toán sau:
>
>- Tìm vị trí xuất hiện đầu tiên của phần tử x trong danh sách locate()
>- Xóa phần tử ở vị trí p trong danh sách deleteList()
>
>Hãy viết hàm xóa phần tử x xuất hiện đầu tiên trong danh sách đặc các số nguyên.

#### Code:
>[erase.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/erase.c)


## 
## getAvg
#### Đề:
>Cho hàm append(x, &L): nối x vào danh sách, hàm này được dùng để thêm dữ liệu cho các test cases.
>
>Hãy viết hàm tính trung bình cộng giá trị các phần tử trong danh sách.

#### Code:
>[getAvg.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/getAvg.c)


## 
## insertList
#### Đề:
>Viết hàm cho phép xen phần tử x vào vị trí p trong danh sách.

#### Code:
>[insertList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/insertList.c)


## 
## intersection
#### Đề:
>Cho trước các phép toán sau:
>
>- Khởi tạo danh sách rỗng makenullList()
>- Kiểm tra phần tử X có trong danh sách hay không member()
>- Nối phần tử x vào danh sách append()
>
>Hãy viết hàm tìm tập hơp giao của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2.

#### Code:
>[intersection.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/intersection.c)


## 
## khaibaods
#### Đề:
>Hãy viết khai báo cho kiểu dữ liệu List với các thành phần được mô tả như hình trên để là một danh sách liên kết đơn các số nguyên
>
#### Code:
>[khaibaods.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/khaibaods.c)

## 
## locate
#### Đề:
>Giả sử kiểu dữ liệu List đã được khai báo. 
>
>Viết hàm cho phép tìm vị trí xuất hiện đầu tiên của x trong danh sách.
>
#### Code:
>[locate.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/locate.c)


## 
## makenullList
#### Đề:
>Giả sử kiểu dữ liệu List đã được khai báo, viết hàm cho phép khởi tạo một danh sách rỗng
>
#### Code:
>[makenullList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/makenullList.c)

## 
## member
#### Đề:
>Hãy viết hàm cho biết phần tử x có tồn tại trong danh sách các số nguyên hay không
>
#### Code:
>[member.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/member.c)

## 
## normalize
#### Đề:
>Cho trước các phép toán sau:
>
>- Xóa phần tử ở vị trí p trong danh sách deleteList()
>- Bên cạnh đó phép toán append(x, &L): nối phần tử x vào danh sách cũng được hỗ trợ để thêm dữ liệu cho các test cases.
>
>Hãy viết hàm chuẩn hóa một danh sách, tức các phần tử trong danh sách nếu trùng nhau thì chỉ giữ lại 1 phần tử, các phần tử khác bị xóa bỏ
>
#### Code:
>[normalize.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/normalize.c)


## 
## readList
#### Đề:
>Giả sử kiểu dữ liệu List đã được khai báo. Cho trước hàm khởi tạo danh sách rỗng: makenullList()
>
>Viết hàm cho phép nhập danh sách từ bàn phím
>
#### Code:
>[readList.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/readList.c)

## 
## readSet
#### Đề:
>Cho trước các phép toán sau:
>
>- Khởi tạo danh sách rỗng makenullList()
>- Kiểm tra phần tử X có trong danh sách hay không member()
>- Thêm phần tử X vào đầu danh sách addFirst()
>- Hãy viết hàm nhập một tập hợp từ bàn phím, khi nhập từng giá trị, nếu 1 giá trị nhập đã có trong tập hợp thì không thêm vào để bảo đảm tập hợp có các giá trị luôn khác nhau
>
#### Code:
>[readSet.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/readSet.c)

## 
## removeAll
#### Đề:
>Cho trước các phép toán sau:
>
>- Tìm vị trí xuất hiện đầu tiên của phần tử x trong danh sách locate()
>- Xóa phần tử ở vị trí p trong danh sách deleteList()
>- Hãy viết hàm xóa tất cả phần tử có giá trị x trong danh sách đặc các số nguyên.
>
#### Code:
>[removeAll.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/removeAll.c)

## 
## sort
#### Đề:
>Cho trước hàm addFirst(x, &L): thêm phần tử x vào đầu danh sách; hàm này để tạo danh sách cho các test cases.
>
>Hãy viết hàm sắp xếp danh sách 
>
#### Code:
>[sort.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/sort.c)

## 
## unionSet
#### Đề:
>Cho trước các phép toán sau:
>
>- Khởi tạo danh sách rỗng makenullList()
>- Kiểm tra phần tử X có trong danh sách hay không member()
>- Nối phần tử x vào danh sách append()
>- Hãy viết hàm tìm tập hơp hợp của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2.
>
#### Code:
>[unionSet.c](https://github.com/huyluongme/Data-Structures/blob/main/Danh_sach_lien_ket/Cac_phep_toan_tren_danh_sach_lien_ket_cac_so_nguyen/unionSet.c)
>
