##
> Cho mô hình một danh sách các số nguyên List biểu diễn một tập hợp như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_lien_ket/Dslk.png)

##
# erase
>Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c, hãy viết chương trình cho phép xóa phần tử x xuất hiện đầu tiên trong danh sách
>
>**Gợi ý**
>
>- #include "PListLib.c"
>- Định nghĩa các hàm nhập và hiển thị danh sách
>- Định nghĩa hàm xóa phần tử x được tìm thấy đầu tiên trong danh sách
>- Hàm main()
>
>        - Gọi thực thi hàm nhập và hiển thị trong hàm main()
>        - Nhập vào một giá trị x
>        - Gọi hàm xóa phần tử x xuất hiện đầu tiên
>        - Hiển thị kết quả
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
><tr>
><td> 5<br>2 6 6 2 6<br>6 </td>
><td> 2 6 6 2 6<br>2 6 2 6 </td>
></tr>
></table>
> **Answer**
> 
> ```c
>#include "PListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
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
>void erase(ElementType x, List* pL) {
>	Position P = locate(x, *pL);
>	if (next(P, *pL) != NULL)
>		deleteList(P, pL);
>}
>
>int main() {
>	List L;
>	readList(&L);
>	ElementType x;
>	scanf("%d", &x);
>	printList(L);
>	erase(x, &L);
>	printf("\n");
>	printList(L);
>	return 0;
>}
> ```


##
# deleteX
>Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c, hãy viết chương trình cho phép xóa phần tử x xuất hiện đầu tiên trong danh sách
>
>**Gợi ý**
>
>- #include "PListLib.c"
>- Định nghĩa các hàm nhập và hiển thị danh sách
>- Định nghĩa hàm xóa tất cả phần tử x trong danh sách
>- Gọi thực thi các hàm trên trong hàm main()
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 6 -10 2 -100<br>2 </td>
><td> 2 6 -10 2 -100<br>6 -10 -100 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>2 6 6 2 6<br>6 </td>
><td> 2 6 6 2 6<br>2 2 </td>
></tr>
></table>
> **Answer**
> 
> ```c
>#include "PListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
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
>	Position P = first(*pL), E = endList(*pL);
>	while (P != E) {
>		if (retrieve(P, *pL) == x) {
>			deleteList(P, pL);
>			E = endList(*pL);
>		}
>		else
>			P = next(P, *pL);
>	}
>}
>
>int main() {
>	List L;
>	readList(&L);
>	ElementType x;
>	scanf("%d", &x);
>	printList(L);
>	deleteX(x, &L);
>	printf("\n");
>	printList(L);
>	return 0;
>}
> ```


##
# difference
>Bằng cách sử dụng những phép toán  trên tập hợp, hãy viết chương trình cho phép tìm hiệu của 2 danh sách biểu diễn tập hợp
>
>**Gợi ý**
>
>- #include "PListLib.c"
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
><td> -100 -10 6 2<br>2 6 3<br>-100 -10 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>20 6 -10 2 -100<br>7<br>3 60 2 -10 6 2 -1 </td>
><td> -100 2 -10 6 20<br>-1 6 -10 2 60 3<br>-100 20 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>2 60 60 2 6<br>5 <br>5 6 7 8 9 </td>
><td> 6 60 2<br>9 8 7 6 5<br>60 2 </td>
></tr>
></table>
> **Answer**
> 
> ```c
>#include "PListLib.c"
>
>List readSet() {
>	List L;
>	makenullList(&L);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
>		scanf("%d", &x);
>		if (locate(x, L) == endList(L))
>			insertList(x, first(L), &L);
>	}
>	return L;
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
>List difference(List L1, List L2) {
>	List L;
>	makenullList(&L);
>	Position P = L1, E = endList(L1), E2 = endList(L2);
>	while (P != E) {
>		if (locate(retrieve(P, L1), L2) == E2)
>			insertList(retrieve(P, L1), endList(L), &L);
>		P = next(P, L1);
>	}
>	return L;
>}
>
>int main() {
>	List L1 = readSet(), L2 = readSet(), L = difference(L1, L2);
>	printList(L1);
>	printf("\n");
>	printList(L2);
>	printf("\n");
>	printList(L);
>	return 0;
>}
> ```


##
# intersection
>Bằng cách sử dụng những phép toán trên tập hợp, hãy viết chương trình cho phép tìm tập hợp giao của 2 danh sách biểu diễn tập hợp
>
>**Gợi ý**
>
>- #include "PListLib.c"
>- Định nghĩa các hàm nhập tập hợp và hiển thị danh sách
>- Định nghĩa hàm tìm tập hợp giao của 2 tập hợp
>- Gọi thực thi các hàm trên trong hàm main()
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 6 -10 2 -100<br>3<br>3 6 2 </td>
><td> -100 -10 6 2<br>2 6 3<br>6 2 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>20 6 -10 2 -100<br>7<br>3 60 2 -10 6 2 -1 </td>
><td> -100 2 -10 6 20<br>-1 6 -10 2 60 3<br>2 -10 6 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>2 60 60 2 6<br>5 <br>5 6 7 8 9 </td>
><td> 6 60 2<br>9 8 7 6 5<br>6 </td>
></tr>
></table>
> **Answer**
> 
> ```c
>#include "PListLib.c"
>
>List readSet() {
>	List L;
>	makenullList(&L);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
>		scanf("%d", &x);
>		if (locate(x, L) == endList(L))
>			insertList(x, first(L), &L);
>	}
>	return L;
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
>List intersection(List L1, List L2) {
>	List L;
>	makenullList(&L);
>	Position P = L1, E = endList(L1), E2 = endList(L2);
>	while (P != E) {
>		if (locate(retrieve(P, L1), L2) != E2)
>			insertList(retrieve(P, L1), endList(L), &L);
>		P = next(P, L1);
>	}
>	return L;
>}
>
>int main() {
>	List L1 = readSet(), L2 = readSet(), L = intersection(L1, L2);
>	printList(L1);
>	printf("\n");
>	printList(L2);
>	printf("\n");
>	printList(L);
>	return 0;
>}
> ```

##
# unionSet
>Bằng cách sử dụng những phép toán trên tập hợp, hãy viết chương trình cho phép tìm tập hợp hợp của 2 danh sách biểu diễn tập hợp
>
>**Gợi ý**
>
>- #include "PListLib.c"
>- Định nghĩa các hàm nhập tập hợp và hiển thị danh sách
>- Định nghĩa hàm tìm tập hợp hợp của 2 tập hợp
>- Gọi thực thi các hàm trên trong hàm main()
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 6 -10 2 -100<br>3<br>3 6 2 </td>
><td> -100 -10 6 2<br>2 6 3<br>-100 -10 6 2 3 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>20 6 -10 2 -100<br>7<br>3 60 2 -10 6 2 -1 </td>
><td> -100 2 -10 6 20<br>-1 6 -10 2 60 3<br>-100 2 -10 6 20 -1 60 3 </td>
></tr>
><tr>
></tr>
><tr>
><td> 5<br>2 60 60 2 6<br>5 <br>5 6 7 8 9 </td>
><td> 6 60 2<br>9 8 7 6 5<br>6 60 2 9 8 7 5 </td>
></tr>
></table>
> **Answer**
> 
> ```c
>#include "PListLib.c"
>
>List readSet() {
>	List L;
>	makenullList(&L);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
>		scanf("%d", &x);
>		if (locate(x, L) == endList(L))
>			insertList(x, first(L), &L);
>	}
>	return L;
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
>List unionSet(List L1, List L2) {
>	List L;
>	makenullList(&L);
>	Position P = L1, E = endList(L1), E2 = endList(L2);
>	while (P != E) {
>		insertList(retrieve(P, L1), endList(L), &L);
>		P = next(P, L1);
>	}
>
>	P = L2;
>	while (P != E2) {
>		if (locate(retrieve(P, L2), L1) == E)
>			insertList(retrieve(P, L2), endList(L), &L);
>		P = next(P, L2);
>	}
>	return L;
>}
>
>int main() {
>	List L1 = readSet(), L2 = readSet(), L = unionSet(L1, L2);
>	printList(L1);
>	printf("\n");
>	printList(L2);
>	printf("\n");
>	printList(L);
>	return 0;
>}
> ```


##
# sort
>Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c, hãy viết chương trình cho phép sắp xếp danh sách tăng dần
>
>**Gợi ý**
>
>- #include "PListLib.c"
>- Định nghĩa các hàm nhập, hiển thị và sắp xếp danh sách
>- Gọi thực thi các hàm trên trong hàm main()
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
> **Answer**
> 
> ```c
>#include "PListLib.h"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
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
>			}
>			else
>				Q = next(Q, *pL);
>		}
>		P = next(P, *pL);
>	}
>}
>
>int main() {
>	List L;
>	readList(&L);
>	printList(L);
>	sort(&L);
>	printf("\n");
>	printList(L);
>	return 0;
>}
> ```

##
# readList_printList
>Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c, hãy viết chương trình cho phép nhập và hiển thị một danh sách số nguyên từ bàn phím
>
>**Gợi ý**
>
>- #include "PListLib.c"
>- Định nghĩa các hàm nhập và hiển thị danh sách
>- Gọi thực thi hàm nhập và hiển thị trong hàm main()
>
>**For example:**
><table>
><tr>
><td> Input </td> <td> Result </td>
></tr>
><tr>
><td> 5<br>2 6 -10 2 -100 </td>
><td> 2 6 -10 2 -100 </td>
></tr>
></table>
> **Answer**
> 
> ```c
>#include "PListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
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
>int main() {
>	List L;
>	readList(&L);
>	printList(L);
>	return 0;
>}
> ```

##
# getAvg
>Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c, hãy viết chương trình cho phép tính trung bình cộng các phần tử trong danh sách
>
>**Gợi ý**
>
>- #include "PListLib.c"
>- Định nghĩa các hàm nhập, hiển thị, trung bình cộng các phần tử
>- Gọi thực thi các hàm trên trong hàm main()
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
> **Answer**
> 
> ```c
>#include "PListLib.h"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
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
>float getAvg(List L) {
>	float result = 0;
>	int count = 0;
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		result += retrieve(P, L);
>		count++;
>		P = next(P, L);
>	}
>	return result / count;
>}
>
>int main() {
>	List L;
>	readList(&L);
>	printList(L);
>	printf("\n%.3f", getAvg(L));
>	return 0;
>}
> ```

##
# printEven_AvgofEvenNums
>Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c, hãy viết chương trình cho phép liệt kê các số chẵn và tính trung bình cộng các phần tử là số chẵn trong danh sách
>
>**Gợi ý**
>
>- #include "PListLib.c"
>- Định nghĩa các hàm nhập, hiển thị, trung bình cộng các phần tử
>- Định nghĩa hàm chép các số chẵn sang danh sách kết quả
>- Gọi thực thi các hàm trên trong hàm main()
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
> **Answer**
> 
> ```c
>#include "PListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
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
>void printEven_AvgofEvenNums(List L) {
>	int count = 0;
>	float sum = 0;
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		if (retrieve(P, L) % 2 == 0) {
>			printf("%d ", retrieve(P, L));
>			count++;
>			sum += retrieve(P, L);
>		}
>		P = next(P, L);
>	}
>	printf("\n%.3f", sum / count);
>}
>
>int main() {
>	List L;
>	readList(&L);
>	printList(L);
>	printf("\n");
>	printEven_AvgofEvenNums(L);
>	return 0;
>}
> ```


##
# printOddEvenNumbers
>Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c, hãy viết chương trình cho phép liệt kê các số lẻ, số chẵn trong danh sách
>
>**Gợi ý**
>
>- #include "PListLib.c"
>- Định nghĩa các hàm nhập, hiển thị, liệt kê các số nguyên lẻ
>- Định nghĩa hàm chép các số nguyên chẵn sang danh sách kết quả
>- Gọi thực thi các hàm trên trong hàm main()
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
> **Answer**
> 
> ```c
>#include "PListLib.c"
>
>void readList(List* pL) {
>	makenullList(pL);
>	int n;
>	ElementType x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
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
>void printOddEvenNumbers(int num_type, List L) {
>	Position P = first(L), E = endList(L);
>	while (P != E) {
>		if (num_type == 0) {
>			if (retrieve(P, L) % 2 == 0)
>				printf("%d ", retrieve(P, L));
>		}
>		else if (num_type == 1)
>			if (retrieve(P, L) % 2 != 0)
>				printf("%d ", retrieve(P, L));
>
>		P = next(P, L);
>	}
>}
>
>int main() {
>	List L;
>	readList(&L);
>	printList(L);
>	printf("\n");
>	printOddEvenNumbers(1, L);
>	printf("\n");
>	printOddEvenNumbers(0, L);
>	return 0;
>}
> ```
