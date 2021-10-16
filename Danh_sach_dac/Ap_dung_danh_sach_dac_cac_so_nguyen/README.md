##
# Thư viện **AListLib.c**
>```c
>#include <stdio.h>
>
>#define MaxLenght 100
>
>typedef int ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType Elements[MaxLenght];
>	Position Last;
>}List;
>
>void makenullList(List* pL) {
>	pL->Last = 0;
>}
>
>int emptyList(List L) {
>	return L.Last == 0;
>}
>
>int fullList(List L) {
>	return L.Last == MaxLenght;
>}
>
>Position first(List L) {
>	return 1;
>}
>
>Position endList(List L) {
>	return L.Last + 1;
>}
>
>Position next(Position P, List L) {
>	return P + 1;
>}
>
>Position previous(Position P, List L) {
>	return P - 1;
>}
>
>ElementType retrieve(Position P, List L) {
>	return L.Elements[P - 1];
>}
>
>void insertList(ElementType X, Position P, List* pL) {
>	if (fullList(*pL))
>		printf("Danh sach day");
>	else if (P < first(*pL) || P > endList(*pL))
>		printf("Vi tri khong hop le");
>	else {
>		for (Position i = endList(*pL) - 1; i >= P; i--)
>			pL->Elements[i] = pL->Elements[i - 1];
>		pL->Elements[P - 1] = X;
>		pL->Last++;
>	}
>}
>
>void deleteList(Position P, List* pL) {
>	if (emptyList(*pL))
>		printf("Danh sach rong");
>	else if (P < 1 || P > endList(*pL))
>		printf("Vi tri khong hop le");
>	else {
>		for (Position i = P; i < endList(*pL) - 1; i++)
>			pL->Elements[i - 1] = pL->Elements[i];
>		pL->Last--;
>	}
>}
>
>Position locate(ElementType X, List L) {
>	Position P = first(L);
>	Position E = endList(L);
>	while (P != E) {
>		if (retrieve(P, L) == X)
>			return P;
>		else
>			P = next(P, L);
>	}
>	return P;
>}
>```

##
# countList
>Để cài đặt cấu trúc [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) với kiểu phần tử là số nguyên, cho trước các khai báo như sau:
>```c
>#define Maxlength 50
>
>
>typedef int ElementType;
>
>
>typedef int Position;
>
>
>typedef struct {
>
>
>  ElementType Elements[Maxlength];
>
>
>  Position    Last;
>
>
>}List;
>```
>
>Các phép toán cơ bản trên danh sách cũng đã được cài đặt.
>```c
>void makenullList(List *L)
>
>int emptyList(List L)
>
>
>Position first(List L)
>
>
>Position endList(List L)
>
>
>Position next(Position P, List L)
>
>
>ElementType retrieve(Position P, List L)
>
>
>void insertList(ElementType X, Position P, List *L)
>
>
>void deleteList(Position P, List *L)
>
>
>void readList(int n,List *L)
>
>
>void printList(List L)
>
>
>Position locate(ElementType X,List L)
>```
>Hãy viết hàm
>```c
>int countList(ElementType X, List L)
>```
> đếm số lần xuất hiện của X trong danh sách L.
>
>**Answer**
>```c
>int countList(ElementType X, List L) {
>	int count = 0;
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		if (retrieve(P, L) == X)
>			count++;
>		P = next(P, L);
>	}
>	return count;
>}
>```

##
# deleteAll
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
>Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép xóa tất cả các phần tử x trong danh sách
>
>**Gợi ý**
>
>- Khai báo sử dụng thư viện AListLib.c
>- Định nghĩa các hàm nhập và hiển thị danh sách
>- Định nghĩa hàm xóa tất cả phần tử x trong danh sách
>- Khai báo biến và gọi thực thi các hàm trên trong hàm main()
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td>5<br>2 6 -10 2 -100<br>2</td>
><td> 2 6 -10 2 -100<br>6 -10 -100 </td>
></tr>
><tr>
></tr>
></tr>
><tr>
><td>5<br>2 6 6 2 6<br>6</td>
><td> 2 6 6 2 6<br>2 2 </td>
></tr>
></table>
>
>**Answer:**
>```c
>#include "AListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 1; i <= n; i++) {
>		scanf("%d", &x);
>		insertList(x, endList(*pL), pL);
>	}
>}
>
>void printList(List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>void deleteAll(ElementType x, List* pL) {
>	Position P = locate(x, *pL);
>	while (P != endList(*pL)) {
>		deleteList(P, pL);
>		P = locate(x, *pL);
>	}
>}
>
>int main()
>{
>	List L;
>	readList(&L);
>	int x;
>	scanf("%d", &x);
>	printList(L);
>	deleteAll(x, &L);
>	printf("\n");
>	printList(L);
>	return 0;
>}
>```

##
# deleteX
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
>Bằng cách sử dụng những phép toán chuẩn trên danh sách đã cho trong thư viện AListLib.c, hãy viết chương trình nhập một danh sách từ bàn phím và cho phép xóa phần tử x xuất hiện đầu tiên trong danh sách
>
>**Gợi ý**
>
>- #include "AListLib.c"
>- Định nghĩa các hàm nhập và hiển thị danh sách
>- Định nghĩa hàm xóa phần tử x được tìm thấy đầu tiên trong danh sách
>- Viết hàm main(): 
>       -  Khai báo một danh sách kiểu List
>       -  Gọi thực thi hàm nhập và hiển thị danh sách
>
>       - Nhập vào một giá trị x
>
>       - Gọi hàm xóa phần tử x xuất hiện đầu tiên
>
>       - Hiển thị kết quả danh sách sau khi xóa
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 6 -10 2 -100<br>2 </td>
><td> 2 6 -10 2 -100<br>6 -10 2 -100 </td>
></tr>
><tr>
></tr>
></tr>
><tr>
><td> 5<br>2 6 6 2 6<br>6 </td>
><td> 2 6 6 2 6<br>2 6 2 6 </td>
></tr>
></table>
>
>**Answer:**
>```c
>#include "AListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 1; i <= n; i++) {
>		scanf("%d", &x);
>		insertList(x, endList(*pL), pL);
>	}
>}
>
>void printList(List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>void deleteX(ElementType x, List* pL) {
>	Position P = locate(x, *pL);
>	if (P != endList(*pL))
>		deleteList(P, pL);
>}
>
>int main()
>{
>	List L;
>	readList(&L);
>	int x;
>	scanf("%d", &x);
>	printList(L);
>	deleteX(x, &L);
>	printf("\n");
>	printList(L);
>	return 0;
>}
>```

##
# difference
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
>Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép tìm hiệu của 2 danh sách biểu diễn tập hợp
>
>**Gợi ý**
>
>- Khai báo sử dụng thư viện AListLib.c 
>- Định nghĩa các hàm nhập tập hợp và hiển thị danh sách
>- Định nghĩa hàm tìm tập hợp hiệu của 2 tập hợp
>- Gọi thực thi các hàm trên trong hàm main()
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 6 -10 2 -100<br>3<br>3 6 2 </td>
><td> 2 6 -10 -100<br>3 6 2<br>-10 -100 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>20 6 -10 2 -100<br>7<br>3 60 2 -10 6 2 -1 </td>
><td> 20 6 -10 2 -100<br>3 60 2 -10 6 -1<br>20 -100 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>2 60 60 2 6<br>5 <br>5 6 7 8 9 </td>
><td> 2 60 6<br>5 6 7 8 9<br>2 60 </td>
></tr>
></table>
>
>**Answer:**
>```c
>#include "AListLib.c"
>
>void readSet(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 1; i <= n; i++) {
>		scanf("%d", &x);
>		if (locate(x, *pL) == endList(*pL))
>			insertList(x, endList(*pL), pL);
>	}
>}
>
>void printList(List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>void difference(List L1, List L2, List* pL) {
>	makenullList(pL);
>	Position P = first(L1), E = endList(L1);
>	while (P != E) {
>		if (locate(retrieve(P, L1), L2) == endList(L2))
>			insertList(retrieve(P, L1), endList(*pL), pL);
>		P = next(P, L1);
>	}
>}
>
>int main()
>{
>	List L1, L2, L;
>	readSet(&L1);
>	readSet(&L2);
>	difference(L1, L2, &L);
>	printList(L1);
>	printf("\n");
>	printList(L2);
>	printf("\n");
>	printList(L);
>	return 0;
>}
>```

##
# getAVG
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
>Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép tính trung bình cộng các phần tử trong danh sách
>
>**Gợi ý**
>
>- Khai báo sử dụng thư viện AListLib.c
>- Định nghĩa các hàm nhập, hiển thị, trung bình cộng các phần tử
>- Khai báo và gọi thực thi các hàm trên trong hàm main()
>
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 4 6 8 10 </td>
><td> 2 4 6 8 10<br>6.000 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>1 6 6 9 -6 </td>
><td> 1 6 6 9 -6<br>3.200 </td>
></tr>
></table>
>
>**Answer:**
>```c
>#include "AListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 1; i <= n; i++) {
>		scanf("%d", &x);
>		insertList(x, endList(*pL), pL);
>	}
>}
>
>void printList(List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>float getAVG(List L) {
>	float result = 0.0;
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		result += retrieve(P, L);
>		P = next(P, L);
>	}
>	return result / (E - 1);
>}
>
>int main()
>{
>	List L;
>	readList(&L);
>	printList(L);
>	printf("\n");
>	printf("%.3f", getAVG(L));
>	return 0;
>}
>```

##
# intersection
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
>Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép tìm tập hợp giao của 2 danh sách biểu diễn tập hợp
>
>**Gợi ý**
>
>- Khai báo sử dụng thư viện danh sách AListLib.c 
>- Định nghĩa các hàm nhập tập hợp và hiển thị danh sách
>- Định nghĩa hàm tìm tập hợp giao của 2 tập hợp
>- Gọi thực thi các hàm trên trong hàm main()
>
>
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 6 -10 2 -100<br>3<br>3 6 2 </td>
><td> 2 6 -10 -100<br>3 6 2<br>2 6 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>20 6 -10 20 -100<br>7<br>3 60 2 -10 6 2 -1 </td>
><td> 20 6 -10 -100<br>3 60 2 -10 6 -1<br>6 -10 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>2 60 60 2 6<br>5 <br>5 6 7 8 9 </td>
><td> 2 60 6<br>5 6 7 8 9<br>6 </td>
></tr>
></table>
>
>**Answer:**
>```c
>#include "AListLib.c"
>
>void readSet(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 1; i <= n; i++) {
>		scanf("%d", &x);
>		if (locate(x, *pL) == endList(*pL))
>			insertList(x, endList(*pL), pL);
>	}
>}
>
>void printList(List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>void intersection(List L1, List L2, List* pL) {
>	makenullList(pL);
>	Position P = first(L1), E = endList(L1);
>	while (P != E) {
>		if (locate(retrieve(P, L1), L2) != endList(L2))
>			insertList(retrieve(P, L1), endList(*pL), pL);
>		P = next(P, L1);
>	}
>}
>
>int main()
>{
>	List L1, L2, L;
>	readSet(&L1);
>	readSet(&L2);
>	intersection(L1, L2, &L);
>	printList(L1);
>	printf("\n");
>	printList(L2);
>	printf("\n");
>	printList(L);
>	return 0;
>}
>```


##
# maxList
>Để cài đặt cấu trúc [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) với kiểu phần tử là số nguyên, cho trước các khai báo như sau:
>```c
>#define Maxlength 50
>
>
>typedef int ElementType;
>
>
>typedef int Position;
>
>
>typedef struct {
>
>
>  ElementType Elements[Maxlength];
>
>
>  Position    Last;
>
>
>}List;
>```
>
>Các phép toán cơ bản trên danh sách cũng đã được cài đặt.
>```c
>void makenullList(List *L)
>
>int emptyList(List L)
>
>
>Position first(List L)
>
>
>Position endList(List L)
>
>
>Position next(Position P, List L)
>
>
>ElementType retrieve(Position P, List L)
>
>
>void insertList(ElementType X, Position P, List *L)
>
>
>void deleteList(Position P, List *L)
>
>
>void readList(int n,List *L)
>
>
>void printList(List L)
>
>
>Position locate(ElementType X,List L)
>```
>Hãy viết hàm
>```c
>ElementType maxList(List L)
>```
> trả về giá trị lớn nhất trong các phần tử của danh sách L.
>
>**Answer**
>```c
>ElementType maxList(List L) {
>	ElementType min = retrieve(first(L), L);
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		if (min < retrieve(P, L))
>			min = retrieve(P, L);
>		P = next(P, L);
>	}
>	return min;
>}
>```


##
# minList
>Để cài đặt cấu trúc [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) với kiểu phần tử là số nguyên, cho trước các khai báo như sau:
>```c
>#define Maxlength 50
>
>
>typedef int ElementType;
>
>
>typedef int Position;
>
>
>typedef struct {
>
>
>  ElementType Elements[Maxlength];
>
>
>  Position    Last;
>
>
>}List;
>```
>
>Các phép toán cơ bản trên danh sách cũng đã được cài đặt.
>```c
>void makenullList(List *L)
>
>int emptyList(List L)
>
>
>Position first(List L)
>
>
>Position endList(List L)
>
>
>Position next(Position P, List L)
>
>
>ElementType retrieve(Position P, List L)
>
>
>void insertList(ElementType X, Position P, List *L)
>
>
>void deleteList(Position P, List *L)
>
>
>void readList(int n,List *L)
>
>
>void printList(List L)
>
>
>Position locate(ElementType X,List L)
>```
>Hãy viết hàm
>```c
>ElementType minList(List L)
>```
> trả về giá trị nhỏ nhất trong các phần tử của danh sách L.
>
>**Answer**
>```c
>ElementType minList(List L) {
>	ElementType min = retrieve(first(L), L);
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		if (min > retrieve(P, L))
>			min = retrieve(P, L);
>		P = next(P, L);
>	}
>	return min;
>}
>```

##
# readList - printList
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
>Cho trước khai báo kiểu List như trên cùng với các phép toán:
>
>     - void readList(List *pL): Nhập một danh sách chỉ bởi con trỏ pL từ bàn phím
>
>     - void printList(List L): hiển thị danh sách L lên màn hình
>
>Và cho hàm main() như sau:
>
>#include <stdio.h>
>```c
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
>Hãy hoàn chỉnh chương trình trên bằng cách điền các lệnh cần thiết vào dấu ...  để tạo thành 1 chương trình cho phép nhập và hiển thị 1 danh sách từ bàn phím.
>
>
>**Gợi ý**
>
>- Chỉ điền kết quả tương ứng với chỗ ..., KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>**Answer:**
>```c
>readList(&L);
>printList(L);
>```

##
# printEvenNum_AVGofEvenNum
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
>Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép liệt kê các số chẵn và tính trung bình cộng các phần tử là số chẵn trong danh sách
>
>**Gợi ý**
>
>- Khai báo sử dụng thư viện AListLib.c
>- Định nghĩa các hàm nhập, hiển thị, trung bình cộng các phần tử
>- Định nghĩa hàm chép các số chẵn sang danh sách kết quả
>- Khai báo biến và gọi thực thi các hàm trên trong hàm main() đáp ứng yêu cầu đặt ra.
>
>
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 -1 6 3 10 </td>
><td> 2 -1 6 3 10<br>2 6 10<br>6.000 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>1 6 2 9 8 </td>
><td> 1 6 2 9 8<br>6 2 8<br>5.333 </td>
></tr>
></table>
>
>**Answer:**
>```c
>#include "AListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 1; i <= n; i++) {
>		scanf("%d", &x);
>		insertList(x, endList(*pL), pL);
>	}
>}
>
>void printList(List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>float getAVG(List L) {
>	float result = 0.0;
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		result += retrieve(P, L);
>		P = next(P, L);
>	}
>	return result / (E - 1);
>}
>
>
>void printEvenNum_AVGofEvenNum(List L) {
>	float avg = 0.0;
>	int count = 0;
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		if (retrieve(P, L) % 2 == 0) {
>			printf("%d ", retrieve(P, L));
>			avg += retrieve(P, L);
>			count++;
>		}
>		P = next(P, L);
>	}
>	printf("\n%.3f", avg / count);
>}
>
>int main()
>{
>	List L;
>	readList(&L);
>	printList(L);
>	printf("\n");
>	printEvenNum_AVGofEvenNum(L);
>	return 0;
>}
>```

##
# printOddEvenNumbers
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
>Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép liệt kê các số lẻ, số chẵn trong danh sách
>
>**Gợi ý**
>
>- Khai báo sử dụng thư viện AListLib.c
>- Định nghĩa các hàm nhập, hiển thị, liệt kê các số nguyên lẻ
>- Định nghĩa hàm chép các số nguyên chẵn sang danh sách kết quả
>- Khai báo biến và gọi thực thi các hàm trên trong hàm main()
>
>
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>3 6 -11 2 -100 </td>
><td> 3 6 -11 2 -100<br>3 -11<br>6 2 -100 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>1 6 6 9 6 </td>
><td> 1 6 6 9 6<br>1 9<br>6 6 6 </td>
></tr>
></table>
>
>**Answer:**
>```c
>#include "AListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 1; i <= n; i++) {
>		scanf("%d", &x);
>		insertList(x, endList(*pL), pL);
>	}
>}
>
>void printList(List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>void printOddEvenNumbers(int numtype, List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		if (numtype == 0) {
>			if (retrieve(P, L) % 2 != 0)
>				printf("%d ", retrieve(P, L));
>		}
>		else if (numtype == 1)
>			if (retrieve(P, L) % 2 == 0)
>				printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>int main()
>{
>	List L;
>	readList(&L);
>	printList(L);
>	printf("\n");
>	printOddEvenNumbers(0, L);
>	printf("\n");
>	printOddEvenNumbers(1, L);
>	return 0;
>}
>```


##
# sort
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
>Bằng cách sử dụng những phép toán chuẩn trên danh sách đã cho trong thư viện AListLib.c, hãy viết chương trình cho phép sắp xếp danh sách tăng dần
>
>**Gợi ý**
>
>- #include "AListLib.c"
>- Định nghĩa các hàm nhập, hiển thị và sắp xếp danh sách
>- Khai báo và gọi thực thi các hàm trên trong hàm main()
>
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 6 -10 2 -100 </td>
><td> 2 6 -10 2 -100<br>-100 -10 2 2 6 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>2 6 6 2 6 </td>
><td> 2 6 6 2 6<br>2 2 6 6 6 </td>
></tr>
></table>
>
>**Answer:**
>```c
>#include "AListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 1; i <= n; i++) {
>		scanf("%d", &x);
>		insertList(x, endList(*pL), pL);
>	}
>}
>
>void printList(List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>void sort(List* pL) {
>	Position P = first(*pL), E = endList(*pL), Q;
>	while (P != E) {
>		Q = next(P, *pL);
>		while (Q != E) {
>			if (retrieve(P, *pL) > retrieve(Q, *pL)) {
>				ElementType x = retrieve(P, *pL), y = retrieve(Q, *pL);
>				deleteList(Q, pL);
>				insertList(x, Q, pL);
>				deleteList(P, pL);
>				insertList(y, P, pL);
>				E = endList(*pL);
>			}
>			Q = next(Q, *pL);
>		}
>		P = next(P, *pL);
>	}
>}
>
>int main()
>{
>	List L;
>	readList(&L);
>	printList(L);
>	sort(&L);
>	printf("\n");
>	printList(L);
>	return 0;
>}
>```

##
# sumList
>Để cài đặt cấu trúc [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) với kiểu phần tử là số nguyên, cho trước các khai báo như sau:
>```c
>#define Maxlength 50
>
>
>typedef int ElementType;
>
>
>typedef int Position;
>
>
>typedef struct {
>
>
>  ElementType Elements[Maxlength];
>
>
>  Position    Last;
>
>
>}List;
>```
>
>Các phép toán cơ bản trên danh sách cũng đã được cài đặt.
>```c
>void makenullList(List *L)
>
>int emptyList(List L)
>
>
>Position first(List L)
>
>
>Position endList(List L)
>
>
>Position next(Position P, List L)
>
>
>ElementType retrieve(Position P, List L)
>
>
>void insertList(ElementType X, Position P, List *L)
>
>
>void deleteList(Position P, List *L)
>
>
>void readList(int n,List *L)
>
>
>void printList(List L)
>
>
>Position locate(ElementType X,List L)
>```
>Hãy viết hàm
>```c
>int sumList(List L)
>```
> trả về tổng giá trị các phần tử trong danh sách L.
>
>**Answer**
>```c
>int sumList(List L) {
>	int result = 0;
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		result += retrieve(P, L);
>		P = next(P, L);
>	}
>	return result;
>}
>```

##
# unionSet
> Cho mô hình một danh sách các số nguyên List như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)
>
> Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép tìm tập hợp hợp của 2 danh sách biểu diễn tập hợp
> 
> **Gợi ý**
> 
>- Khai báo sử dụng thư viện AListLib.c
>- Định nghĩa các hàm nhập tập hợp và hiển thị danh sách
>- Định nghĩa hàm tìm tập hợp hợp của 2 tập hợp
>- Gọi thực thi các hàm trên trong hàm main()
>
>
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 6 -10 2 -100<br>3<br>3 6 2 </td>
><td> 2 6 -10 -100<br>3 6 2<br>2 6 -10 -100 3 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>20 6 -10 20 -100<br>7<br>3 60 2 -10 6 2 -1 </td>
><td> 20 6 -10 -100<br>3 60 2 -10 6 -1<br>20 6 -10 -100 3 60 2 -1 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>2 60 60 2 6<br>5 <br>5 6 7 8 9 </td>
><td> 2 60 6<br>5 6 7 8 9<br>2 60 6 5 7 8 9<br> </td>
></tr>
></table>
>
>**Answer:**
>```c
>#include "AListLib.c"
>
>void readSet(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 1; i <= n; i++) {
>		scanf("%d", &x);
>		if (locate(x, *pL) == endList(*pL))
>			insertList(x, endList(*pL), pL);
>	}
>}
>
>void printList(List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		printf("%d ", retrieve(P, L));
>		P = next(P, L);
>	}
>}
>
>void unionSet(List L1, List L2, List* pL) {
>	makenullList(pL);
>	Position P = first(L1), E = endList(L1);
>	while (P != E) {
>		insertList(retrieve(P, L1), endList(*pL), pL);
>		P = next(P, L1);
>	}
>	P = first(L2), E = endList(L2);
>	while (P != E) {
>		if (locate(retrieve(P, L2), L1) == endList(L1))
>			insertList(retrieve(P, L2), endList(*pL), pL);
>		P = next(P, L2);
>	}
>}
>
>int main()
>{
>	List L1, L2, L;
>	readSet(&L1);
>	readSet(&L2);
>	unionSet(L1, L2, &L);
>	printList(L1);
>	printf("\n");
>	printList(L2);
>	printf("\n");
>	printList(L);
>	return 0;
>}
>```