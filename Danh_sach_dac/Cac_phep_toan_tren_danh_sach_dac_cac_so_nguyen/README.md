##
> Cho mô hình một danh sách các số nguyên như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_dac/Cac_phep_toan_tren_danh_sach_dac_cac_so_nguyen/dsdac2.png)

##
# Khai báo danh sách
> Hãy viết khai báo cho kiểu dữ liệu List (trong đó **MaxLenght=100**) với các thành phần được mô tả như trình trên để là [danh sách đặc](https://else.ctu.edu.vn/pluginfile.php/28667/mod_resource/content/1/Chuong2_DSDac_hk1_2122_In.pdf) các số nguyên
> 
> **Chú ý**
> 
> - Chỉ viết phần khai báo, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
> 
> **For example**
><table>
><tr>
><td> Result </td>
></tr>
><tr>
><td>
>0 2 4 6 8
></td>
></tr>
></table>
>
> **Answer**
> 
> ```c
> #define MaxLenght 100
> 
> typedef int ElementType;
> typedef int Position;
> 
> typedef struct {
>     ElementType Elements[MaxLenght];
>     Position Last;
> }List;
> ```

##
# makenullList
> Viết hàm khởi tạo một danh sách rỗng.
> 
> **Nguyên mẫu (Prototype)**
> 
> - Tên hàm: **makenullList()**
>   
> - Tham số: **con trỏ pL kiểu List**
>   
> - Kiểu trả về: **không**
>   
> 
> **Thân hàm (Body)**
> 
> - Cho nội dung vùng dữ liệu con trỏ pL chỉ tới có trường Last mang giá trị 0.
> 
> **Chú ý**
> 
> - Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>
>L.Last=5;
>printf("%d ",L.Last);
>makenullList(&L);
>printf("%d ",L.Last);
>```
></td>
><td> 5 0 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
> void makenullList(List* pL) {
>     pL->Last = 0;
> }
> ```

##
# insertList
> Hãy viết hàm thêm một phần tử x vào vị trí p trong danh sách số nguyên.
> 
> 
> - Tên hàm: **insertList()**
> 
> - Tham số:
>   
>   - **x -** kiểu số nguyên
>   - **p -** kiểu vị trí (là số nguyên)
>   - **pL** - con trỏ kiểu List
> 
> **Thân hàm (Body)**
> 
> - Kiểm tra vị trí thêm vào hợp lệ thì thêm phần tử x vào vị trí p trong danh sách được chỉ bởi con trỏ pL
> 
> **Chú ý**
> 
> - Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>{
>    insertList(i*2,L.Last+1,&L);
>}
>for(i=0;i<L.Last;i++)
>{
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 0 2 4 6 8 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>#define MaxLenght 100
>
>void insertList(ElementType x, Position p, List* pL) {
>	if (pL->Last == MaxLenght)
>		printf("Danh sach day\n");
>	else if (p < 1 || p > pL->Last + 1)
>		printf("Vi tri khong hop le\n");
>	else {
>		for (Position Q = pL->Last; Q >= p; Q++)
>			pL->Elements[Q] = pL->Elements[Q - 1];
>		pL->Elements[p - 1] = x;
>		pL->Last++;
>	}
>}
> ```

##
# deleteList
> Hãy viết hàm xóa phần tử ở vị trí p trong danh sách
> 
> - Tên hàm: **deleteList()**
>   
> - Tham số:
>   
> 	- **p -** kiểu vị trí (là số nguyên)
> 	- **pL -** con trỏ kiểu List
> 
> **Thân hàm (Body)**
> 
> - Kiểm tra vị trí xóa là hợp lệ thì xóa phần tử ở vị trí này trong danh sách được chỉ bởi con trỏ pL
> 
> **Chú ý**
> 
> - Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>{
>    L.Elements[i] = 2*i;
>}
>L.Last=5;
>deleteList(2,&L);
>for(i=0;i<L.Last;i++)
>{
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 0 4 6 8 </td>
></tr>
><tr>
></tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>{
>    L.Elements[i] = 2*i;
>}
>L.Last=5;
>deleteList(1,&L);
>for(i=0;i<L.Last;i++)
>{
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 2 4 6 8 </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>{
>    L.Elements[i] = 2*i;
>}
>L.Last=5;
>deleteList(6,&L);
>for(i=0;i<L.Last;i++)
>{
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td>Vi tri khong hop le <br> 0 2 4 6 8 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void deleteList(Position p, List* pL) {
>	if (p < 1 || p > pL->Last)
>		printf("Vi tri khong hop le\n");
>	else {
>		for (Position Q = p; Q < pL->Last + 1; Q++)
>			pL->Elements[Q - 1] = pL->Elements[Q];
>		pL->Last--;
>	}
>}
> ```

##
# insertSet
> Hãy viết hàm chèn một phần tử X vào cuối danh sách chỉ bởi con trỏ  pL biểu diễn 1 tập hợp
> 
> **Nguyên mẫu (Prototype)**
> 
> - Tên hàm (function name): **insertSet**()
> - Tham số (parameters):
> 	- **x -** kiểu phần tử (là số nguyên)
> 	- **pL -** con trỏ kiểu List
> - Kiểu trả về: không
> 
> **Thân hàm (Body)**
> 
> - Chèn x vào sau vị trí cuối của danh sách chỉ bởi con trỏ pL
> 
> **Chú ý**
> 
> - Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
> **Gợi ý**
> 
> - Đưa X vào chỉ số Last của mảng Elements
> - Số phần tử Last tăng 1
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i!=5;i++)
>    insertSet(2*i, &L);
>insertSet(0,&L);
>insertSet(8,&L);
>for(i=0;i<L.Last;i++)
>    {printf("%d ",L.Elements[i]);}
>```
></td>
><td> 0 2 4 6 8 0 8 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>#define MaxLenght 100
>
>void insertSet(ElementType x, List* pL) {
>	if (pL->Last == MaxLenght)
>		printf("Danh sach day\n");
>	else {
>		pL->Elements[pL->Last] = x;
>		pL->Last++;
>	}
>}
> ```

##
# locate
> Hãy viết hàm tìm vị trí xuất hiện đầu tiên của phần tử x trong danh sách các số nguyên.
> 
> - Tên hàm: **locate()**
>   
> - Tham số:
>   
> 	- **x -** kiểu phần tử (là số nguyên)
> 	- **L -** kiểu List
> 
> **Thân hàm (Body)**
> 
> - Trả về vị trí xuất hiện đầu tiên của x trong danh sách L, nếu X không có trong L, kết quả trả về là L.Last+1
> 
> **Chú ý**
> 
> - Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>Position p;
>L.Last=0;
>for(i=0;i<=6;i++)
>    L.Elements[i] = 2*i;
>
>for(i=0;i<=10;i++)
>    L.Elements[i] = 2*i;
>
>L.Last=11;
>p=locate(0,L);
>printf("0 at %d",p);
>```
></td>
><td> 0 at 1 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>Position p;
>L.Last=0;
>for(i=0;i<10;i++)
>    L.Elements[i] = 2*i;
>
>L.Last=10;
>p=locate(12,L);
>printf("8 at %d",p);
>```
></td>
><td> 8 at 7 </td>
></tr>
><tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>Position p;
>L.Last=0;
>for(i=0;i<5;i++)
>    L.Elements[i] = 2*i;
>L.Last=5;
>p=locate(10,L);
>//if (p<L.Last+1)
>//    printf("Found at %d",p);
>//else 
>printf("Not found p = %d",p);
>```
></td>
><td>Not found p = 6 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>Position locate(ElementType x, List L) {
>	Position P = 1;
>	while (P != L.Last + 1)
>		if (L.Elements[P - 1] == x)
>			return P;
>		else
>			P += 1;
>	return P;
>}
> ```


##
# member
> Hãy viết hàm cho biết phần tử x có tồn tại trong danh sách các số nguyên hay không
> 
> - Tên hàm: **member()**
>   
> - Tham số:
>   
> 	- **x -** kiểu phần tử (là số nguyên)
> 	- **L -** kiểu List
> 
> **Thân hàm (Body)**
> 
> - Nếu x có trong danh sách, kết quả trả về là 1, ngược lại kết quả trả về là 0
>
> **Chú ý**
> 
> - Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
> 
> **Gợi ý**
> 
> - Dùng tìm kiếm tuyến tính như hàm **locate()**, tuy nhiên kết quả trả về là đúng (1) hoặc sai (0)
>
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>    L.Elements[i] = 2*i;
>L.Last=5;
>if(member(0,L))
>    printf("0 in L");
>else printf("0 not in L");
>```
></td>
><td> 0 in L </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>    L.Elements[i] = 2*i;
>L.Last=5;
>if(member(8,L))
>    printf("8 in L");
>else printf("8 not in L");
>```
></td>
><td> 8 in L </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>    L.Elements[i] = 2*i;
>L.Last=5;
>if(member(100,L))
>    printf("100 in L");
>else printf("100 not in L");
>```
></td>
><td>100 not in L </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>int member(ElementType x, List L) {
>	for (Position P = 1; P < L.Last + 1; P++)
>		if (L.Elements[P - 1] == x) return 1;
>	return 0;
>}
> ```

##
# readList
>Cho trước các phép toán sau:
>
>- Khởi tạo danh sách rỗng **makenullList()**
>- Chèn phần tử x vào vị trí p trong danh sách **insertList()**
>
>Hãy viết hàm nhập danh sách số nguyên từ bàn phím.
>
> - Tên hàm (function name): **readList()**
> - Tham số (parameters):
>   - **pL -** con trỏ kiểu List
> - Kiểu trả về: Không
>
>**Thân hàm (Body)**
>
> - Nhập từ bàn phím các phần tử của danh sách chỉ bởi con trỏ pL
>
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
> - Khởi tạo danh sách rỗng
> - Nhập số phần tử của danh sách n
> - Lặp  ∀i = 1,n
>
>       - Nhập phần tử x
>       - Chèn x vào sau vị trí cuối cùng trong danh sách
>
> **For example**
><table>
><tr>
><td> Test </td> <td> Input </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>readList(&L);
>for(i=0;i<L.Last;i++)
>    {printf("%d ",L.Elements[i]);}
>```
></td>
><td> 5 <br> 1 3 5 7 9 </td>
><td> 1 3 5 7 9 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>readList(&L);
>for(i=0;i<L.Last;i++)
>   { printf("%d ",L.Elements[i]);}
>```
></td>
><td> 1 <br> 3 </td>
><td> 3 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void readList(List* pL) {
>	makenullList(pL);
>	scanf("%d", &pL->Last);
>	
>	for (Position P = 1; P < pL->Last + 1; P++)
>		scanf("%d", &pL->Elements[P - 1]);
>}
> ```


##
# readSet
>Cho trước các phép toán sau:
>
> - Khởi tạo danh sách rỗng void **makenullList**(List *pL)
>- Kiểm tra phần tử X có trong danh sách hay không int **member**(ElementType x, List L)
>- Thêm phần tử X vào cuối danh sách void **insertSet**(ElementType x, List *pL)
>
>
>Hãy viết hàm nhập một tập hợp từ bàn phím
>
>
>
>**Nguyên mẫu (Prototype)**
>
>
>- Tên hàm (function name): **readSet()**
>- Tham số (parameters):
>   - **pL -** con trỏ kiểu List
>- Kiểu trả về: không
>**Thân hàm (Body)**
>
>- Nhập các các phần tử của một tập hợp từ bàn phím
>
>
>**Chú ý**
>
>-Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
>- Khởi tạo danh sách biểu diễn tập hợp là rỗng
>- Nhập số phần tử n
>- ∀i=1,n
>
>       - Nhập 1 phần tử x
>       - Chèn x vào tập hợp nhờ gọi hàm insetSet()
>
> **For example**
><table>
><tr>
><td> Test </td> <td> Input </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>readSet(&L);
>for(i=0;i<L.Last;i++){
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 4 <br> 1 -10 2 2 </td>
><td> 1 -10 2 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void readSet(List* pL) {
>	makenullList(pL);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
>		scanf("%d", &x);
>		if (!member(x, *pL))
>			insertSet(x, pL);
>	}
>}
> ```

##
# copyEvenNumbers
>Cho trước các phép toán sau:
>
>- Khởi tạo danh sách rỗng **makenullList()**
>- Chèn phần tử x vào vị trí p trong danh sách **insertList()**
>
>Hãy viết hàm chép toàn bộ các số chẵn trong danh sách L1 sang danh sách kết quả.
>
> **Nguyên mẫu (Prototype)**
>
> - Tên hàm (function name): **copyEvenNumbers()**
> - Tham số (parameters):
> - **L1 -** kiểu List
> - **pL2 -** con trỏ kiểu List
> - Kiểu trả về: Không
>
>**Thân hàm (Body)**
>
> - Chép tất cả các số chẵn trong danh sách L1 sang danh sách chỉ bởi con trỏ pL2
>
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
> - Khởi tạo danh sách kết quả là rỗng
> - Duyệt qua danh sách thứ nhất, xét từng phần tử của danh sách này, nếu phần tử đó là số chẵn thì chèn phần tử đó vào sau vị trí cuối cùng trong danh sách kết quả
>
> **For example**
><table>
><tr>
><td> Test </td>  <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L1,L2;
>int i;
>makenullList(&L1);
>for(i=0;i<=5;i++){
>    insertList(i, L1.Last+1, &L1);
>}
>copyEvenNumbers(L1, &L2);
>for(i=0;i<L1.Last;i++){
>    printf("%d ",L1.Elements[i]);
>}
>printf("\n");
>for(i=0;i<L2.Last;i++){
>    printf("%d ",L2.Elements[i]);
>}
>```
></td>
><td> 0 1 2 3 4 5 <br>0 2 4 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L1,L2;
>int i;
>makenullList(&L1);
>insertList(-7, L1.Last+1, &L1);
>insertList(6, L1.Last+1, &L1);
>insertList(-70, L1.Last+1, &L1);
>insertList(21, L1.Last+1, &L1);
>insertList(29, L1.Last+1, &L1);
>
>copyEvenNumbers(L1, &L2);
>
>for(i=0;i<L1.Last;i++){
>    printf("%d ",L1.Elements[i]);
>}
>printf("\n");
>for(i=0;i<L2.Last;i++)
>   { printf("%d ",L2.Elements[i]);}
>```
></td>
><td> -7 6 -70 21 29 <br> 6 -70 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void copyEvenNumbers(List L1, List* pL2) {
>	makenullList(pL2);
>	for (Position P = 1; P < L1.Last + 1; P++)
>		if (L1.Elements[P - 1] % 2 == 0)
>			insertList(L1.Elements[P - 1], pL2->Last + 1, pL2);
>}
> ```

##
# printList
>Hãy viết hàm liệt kê tất cả các phần tử của danh sách các số nguyên.
> 
> 
> - Tên hàm (function name): **printList()**
> - Tham số (parameters):
> - **L -** kiểu List
> - Kiểu trả về: Không
>
> **Thân hàm (Body)**
> 
> - Hiển thị giá trị của các phần tử trong danh sách
> 
> **Chú ý**
> 
> - Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>  {  L.Elements[i] = 2*i; }
>L.Last=5;
>printList(L);
>```
></td>
><td> 0 2 4 6 8 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void printList(List L) {
>	for (Position P = 1; P < L.Last + 1; P++)
>		printf("%d ", L.Elements[P - 1]);
>}
> ```

##
# printOddNumbers
>Hãy viết hàm liệt kê tất cả các phần tử là số lẻ trong danh sách.
>
>
>- Tên hàm (function name): **printOddNumbers()**
>- Tham số (parameters):
>   - **L** - kiểu List
>- Kiểu trả về: Không
>
>**Thân hàm (Body)**
>
>- Hiển thị giá trị của các số lẻ trong danh sách L
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
>- Duyệt qua danh sách L, nếu phần tử là số lẻ thì hiển thị ra
>
> **For example**
><table>
><tr>
><td> Test </td>  <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>{
>    L.Elements[i] = i;
>}
>L.Last=5;
>printOddNumbers(L);
>```
></td>
><td> 1 3 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>L.Elements[0] = -1;
>L.Elements[1] = 2;
>L.Elements[2] = 9;
>L.Elements[3] = -1;
>L.Elements[4] = -10;
>L.Last=5;
>printOddNumbers(L);
>```
></td>
><td> -1 9 -1 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void printOddNumbers(List L) {
>	for (Position P = 1; P < L.Last + 1; P++)
>		if (L.Elements[P - 1] % 2 != 0)
>			printf("%d ", L.Elements[P - 1]);
>}
> ```

##
# erase
>Cho trước các phép toán sau:
>
>
>- Tìm vị trí xuất hiện đầu tiên của phần tử x trong danh sách locate()
>- Xóa phần tử ở vị trí p trong danh sách deleteList()
>
>Hãy viết hàm xóa phần tử x xuất hiện đầu tiên trong danh sách đặc các số nguyên.
>
>
>- Tên hàm (function name): **erase()**
>- Tham số (parameters):
>   - **x** - kiểu phần tử (là số nguyên)
>   - **pL** - con trỏ kiểu List
>- Kiểu trả về: Không
>
>**Thân hàm (Body)**
>
>- Xóa phần tử đầu tiên có giá trị là x trong danh sách chỉ bởi con trỏ pL
>
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
>- Gọi p là vị trí xuất hiện đầu tiên của x trong danh sách. Nếu p là một vị trí hợp lệ thì xóa phần tử ở vị trí p
>
> **For example**
><table>
><tr>
><td> Test </td>  <td> Result </td>
></tr>
><tr>
><td>
>
>```c
> List L;
> int i;
> L.Last=0;
> for(i=0;i<10;i++)
>   {  L.Elements[i] = 2*i;}
> L.Last=10;
> erase(0,&L);
> for(i=0;i<L.Last;i++)
>    { printf("%d ",L.Elements[i]);}
>```
></td>
><td> 2 4 6 8 10 12 14 16 18 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>   { L.Elements[i] = 2*i;}
>L.Last=5;
>erase(8,&L);
>for(i=0;i<L.Last;i++)
> {   printf("%d ",L.Elements[i]);}
>```
></td>
><td> 0 2 4 6 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>  {  L.Elements[i] = 2*i;}
>L.Elements[i] = 2;
>L.Last=6;
>erase(2,&L);
>for(i=0;i<L.Last;i++)
>    {printf("%d ",L.Elements[i]);}
>```
></td>
><td> 0 4 6 8 2 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void erase(ElementType x, List* pL) {
>	Position P = locate(x, *pL);
>	if (P != pL->Last + 1)
>		deleteList(P, pL);
>}
> ```

##
# difference
>Cho trước các phép toán sau:
>
>- Khởi tạo danh sách rỗng void **makenullList**(List *pL)
>- Kiểm tra phần tử X có trong danh sách hay không int **member**(ElementType x, List L)
>- Thêm phần tử X vào cuối danh sách void **insertSet**(ElementType x, List *pL)
>
>
>Hãy viết hàm tìm tập hơp hiệu của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2.
>
>
>
>**Nguyên mẫu (Prototype)**
>
>
>- Tên hàm (function name): **difference()**
>- Tham số (parameters):
>- **L1, L2** - kiểu List
>- **pL** - con trỏ kiểu List
>- Kiểu trả về: không
>
>**Thân hàm (Body)**
>
>- Tính tập hợp hiệu của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2; kết quả được ghi nhận bởi danh sách chỉ bởi con trỏ pL
>
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
>- Khởi tạo danh sách kết quả là rỗng
>- Duyệt qua danh sách thứ nhất, xét từng phần tử của danh sách này, dùng hàm member kiểm tra nếu phần tử đó không thuộc danh sách thứ hai thì chèn phần tử đó vào danh sách kết quả
>
> **For example**
><table>
><tr>
><td> Test </td>  <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L1,L2,L;
>int i;
>
>makenullList(&L1);
>makenullList(&L2);
>
>for(i=0;i<=5;i++){
>    insertSet(2*i, &L1);
>}
>for(i=4;i<=8;i++){
>    insertSet(2*i, &L2);
>}
>
>for(i=0;i<L1.Last;i++){
>    printf("%d ",L1.Elements[i]);
>}
>printf("\n");
>for(i=0;i<L2.Last;i++){
>    printf("%d ",L2.Elements[i]);
>}
>printf("\n");
>difference(L1,L2,&L);
>for(i=0;i<L.Last;i++){
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 0 2 4 6 8 10
<br>8 10 12 14 16
<br>0 2 4 6 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L1,L2,L;
>int i;
>
>makenullList(&L1);
>makenullList(&L2);
>
>for(i=0;i<=5;i++){
>    insertSet(2*i, &L1);
>}
>for(i=10;i>=4;i--){
>    insertSet(2*i, &L2);
>}
>
>for(i=0;i<L1.Last;i++){
>    printf("%d ",L1.Elements[i]);
>}
>printf("\n");
>for(i=0;i<L2.Last;i++){
>    printf("%d ",L2.Elements[i]);
>}
>printf("\n");
>difference(L1,L2,&L);
>for(i=0;i<L.Last;i++){
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 0 2 4 6 8 10
<br>20 18 16 14 12 10 8
<br>0 2 4 6 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void difference(List L1, List L2, List* pL) {
>	makenullList(pL);
>	for (Position P = 1; P < L1.Last + 1; P++)
>		if (!member(L1.Elements[P - 1], L2))
>			insertSet(L1.Elements[P - 1], pL);
>}
> ```

##
# getAvg
>Hãy viết hàm tính trung bình cộng giá trị các phần tử trong danh sách.
>
>
>Tên hàm (function name): **getAvg()**
>- Tham số (parameters):
>   - **L** - kiểu List
>- Kiểu trả về: float
>**Thân hàm (Body)**
>
>- Trả về trung bình cộng giá trị các phần tử trong danh sách, nếu danh sách không có phần tử nào thì kết quả trả về của hàm là -10000.0000
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
>- Gọi S là tổng của tất cả giá trị các phần tử, ban đầu S=0
>- Duyệt qua danh sách L, tại mỗi phần tử tính lại S = S + giá trị phần tử đó
>- Trung bình cộng = S/(Số phần tử trong danh sách)
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>    L.Elements[i] = i+1;
>L.Last=5;
>printf("AVG = %.4f\n", getAvg(L));
>```
></td>
><td> AVG = 3.0000 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>float getAvg(List L) {
>	if (L.Last == 0)
>		return -10000.0;
>	else {
>		float result = 0.0;
>
>		for (Position P = 1; P < L.Last + 1; P++)
>			result += L.Elements[P - 1];
>
>		return  result / L.Last;
>	}
>}
> ```


##
# intersection
>Cho trước các phép toán sau:
>
>- Khởi tạo danh sách rỗng void **makenullList**(List *pL)
>- Kiểm tra phần tử X có trong danh sách hay không int **member**(ElementType x, List L)
>- Thêm phần tử X vào cuối danh sách void **insertSet**(ElementType x, List *pL)
>
>
>Hãy viết hàm tìm tập hơp giao của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2.
>
>
>
>**Nguyên mẫu (Prototype)**
>
>
>- Tên hàm (function name): **intersection()**
>- Tham số (parameters):
>   - **L1, L2** - kiểu List
>   - **pL** - con trỏ kiểu List
>- Kiểu trả về: không
>
>**Thân hàm (Body)**
>
>- Tính tập hợp giao của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2; kết quả được ghi nhận bởi danh sách chỉ bởi con trỏ pL
>
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
>- Khởi tạo danh sách kết quả là rỗng
>-  Duyệt qua danh sách thứ nhất, xét từng phần tử của danh sách này, dùng hàm member kiểm tra nếu phần tử đó thuộc danh sách thứ hai thì chèn phần tử đó vào danh sách kết quả
>
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L1,L2,L;
>int i;
>
>makenullList(&L1);
>makenullList(&L2);
>
>for(i=0;i<=5;i++){
>    insertSet(2*i, &L1);
>}
>for(i=4;i<=8;i++){
>    insertSet(2*i, &L2);
>}
>
>for(i=0;i<L1.Last;i++){
>    printf("%d ",L1.Elements[i]);
>}
>printf("\n");
>for(i=0;i<L2.Last;i++){
>    printf("%d ",L2.Elements[i]);
>}
>printf("\n");
>intersection(L1,L2,&L);
>for(i=0;i<L.Last;i++){
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 0 2 4 6 8 10<br>8 10 12 14 16<br>8 10 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L1,L2,L;
>int i;
>
>makenullList(&L1);
>makenullList(&L2);
>
>for(i=5;i>=0;i--){
>    insertSet(2*i, &L1);
>}
>for(i=9;i>=4;i--){
>    insertSet(2*i, &L2);
>}
>
>for(i=0;i<L1.Last;i++){
>    printf("%d ",L1.Elements[i]);
>}
>printf("\n");
>for(i=0;i<L2.Last;i++){
>    printf("%d ",L2.Elements[i]);
>}
>printf("\n");
>intersection(L1,L2,&L);
>for(i=0;i<L.Last;i++){
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 10 8 6 4 2 0<br>18 16 14 12 10 8<br>10 8 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void intersection(List L1, List L2, List* pL) {
>	makenullList(pL);
>	for (Position P = 1; P < L1.Last + 1; P++)
>		if (member(L1.Elements[P - 1], L2))
>			insertSet(L1.Elements[P - 1], pL);
>}
> ```


##
# normalize
>Cho trước các phép toán sau:
>
>- Xóa phần tử ở vị trí p trong danh sách void **deleteList**(Position p, List *pL)
>
>Hãy viết hàm chuẩn hóa một danh sách, tức các phần tử trong danh sách nếu trùng nhau thì chỉ giữ lại 1 phần tử, các phần tử khác bị xóa bỏ
>
>- Tên hàm (function name): **normalize()**
>- Tham số (parameters):
>   - **pL** - con trỏ kiểu List
>- Kiểu trả về: Không
>
>**Thân hàm (Body)**
>
>- Các phần tử trùng nhau trong danh sách chỉ bởi con trỏ pL bị xóa bở chỉ giữ lại 1 phần tử đầu tiên
>
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
>- p = vị trí đầu tiên trong danh sách
>- Trong khi  (p != Sau vị trí cuối cùng)
>          - q = p+1
>
>          - Trong khi (**q != Sau vị trí cuối cùng**)
>
>                + Nếu (phần tử tại vị trí p == phần tử tại vị trí q) 
>
>                          Xóa phần tử tại vị trí q
>
>                + Ngược lại q= vị trí kế của q
>
>          - p = vị trí kế của p
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last = 6;
>L.Elements[0] = 0;
>L.Elements[1] = 14;
>L.Elements[2] = 10;
>L.Elements[3] = -100;
>L.Elements[4] = 14;
>L.Elements[5] = 14;
>normalize(&L);
>for(i=0;i<L.Last;i++)
>{
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 0 14 10 -100 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last = 6;
>L.Elements[0] = 0;
>L.Elements[1] = 0;
>L.Elements[2] = 0;
>L.Elements[3] = 10;
>L.Elements[4] = 10;
>L.Elements[5] = 10;
>normalize(&L);
>for(i=0;i<L.Last;i++)
>{
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 0 10 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void normalize(List* pL) {
>	for (Position P = 1; P < pL->Last + 1; P++)
>		for (Position Q = P + 1; Q < pL->Last + 1; Q++)
>			if (pL->Elements[P - 1] == pL->Elements[Q - 1]) {
>				deleteList(Q, pL);
>				Q--;
>			}
>}
> ```


##
# unionSet
> Cho trước các phép toán sau:
> 
>- Khởi tạo danh sách rỗng void **makenullList**(List *pL)
>- Kiểm tra phần tử X có trong danh sách hay không int **member**(ElementType x, List L)
>- Thêm phần tử X vào cuối danh sách void **insertSet**(ElementType x, List *pL)
> 
> 
> Hãy viết hàm tìm tập hơp hợp của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2.
> 
> 
> 
> **Nguyên mẫu (Prototype)**
> 
> 
> - Tên hàm (function name): **unionSet()**
> - Tham số (parameters):
>   - **L1, L2** - kiểu List
>   - **pL** - con trỏ kiểu List
> - Kiểu trả về: không
>
> **Thân hàm (Body)**
> 
>- Tính tập hợp hợp của 2 tập hợp biểu diễn bởi 2 danh sách L1, L2; kết quả được ghi nhận bởi danh sách chỉ bởi con trỏ pL
> 
> 
> **Chú ý**
> 
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
> 
> 
> **Gợi ý**
> 
>- Khởi tạo danh sách kết quả là rỗng
>- Đưa toàn bộ danh sách thứ nhất vào danh sách kết quả
>- Duyệt qua danh sách thứ hai, xét từng phần tử của danh sách này, dùng hàm member kiểm tra nếu phần tử đó không thuộc danh sách kết quả thì chèn phần tử đó vào danh sách kết quả
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L1,L2,L;
>int i;
>
>makenullList(&L1);
>makenullList(&L2);
>
>for(i=0;i<=5;i++){
>    insertSet(2*i, &L1);
>}
>for(i=4;i<=8;i++){
>    insertSet(2*i, &L2);
>}
>
>for(i=0;i<L1.Last;i++){
>    printf("%d ",L1.Elements[i]);
>}
>printf("\n");
>for(i=0;i<L2.Last;i++){
>    printf("%d ",L2.Elements[i]);
>}
>printf("\n");
>unionSet(L1,L2,&L);
>for(i=0;i<L.Last;i++){
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td>  2 4 6 8 10<br>8 10 12 14 16<br>0 2 4 6 8 10 12 14 16 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L1,L2,L;
>int i;
>
>makenullList(&L1);
>makenullList(&L2);
>
>for(i=0;i<=5;i++){
>    insertSet(2*i, &L1);
>}
>for(i=10;i>=4;i--){
>    insertSet(2*i, &L2);
>}
>
>for(i=0;i<L1.Last;i++){
>    printf("%d ",L1.Elements[i]);
>}
>printf("\n");
>for(i=0;i<L2.Last;i++){
>    printf("%d ",L2.Elements[i]);
>}
>printf("\n");
>unionSet(L1,L2,&L);
>for(i=0;i<L.Last;i++){
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td> 0 2 4 6 8 10<br>20 18 16 14 12 10 8<br>0 2 4 6 8 10 20 18 16 14 12 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void unionSet(List L1, List L2, List* pL) {
>	makenullList(pL);
>
>	for (Position P = 1; P < L1.Last + 1; P++)
>		insertSet(L1.Elements[P - 1], pL);
>
>	for (Position P = 1; P < L2.Last + 1; P++)
>		if (!member(L2.Elements[P - 1], L1))
>			insertSet(L2.Elements[P - 1], pL);
>}
> ```


##
# sort
>Hãy viết hàm sắp xếp danh sách 
>
>- Tên hàm (function name): **sort()**
>- Tham số (parameters):
>   - **pL** - con trỏ kiểu List
>- Kiểu trả về: Không
>
>**Thân hàm (Body)**
>
>- Sắp xếp tăng dần danh sách chỉ bởi con trỏ pL
>
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
>- Lặp  ∀p=1,Sauvịtrícuốicùng
>
>          - Lặp  ∀q=p+1,Sauvịtrícuốicùng
>
>                  + Nếu (phần tử tại vị trí p > phần tử tại vị trí q)
>
>                         Đổi chỗ giá trị 2 phần tử này cho nhau
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last = 0;
>for(i=5;i>=1;i--){
>    L.Elements[5-i] = 2*i;
>}
>L.Last = 5;
>sort(&L);
>
>for(i=0;i<L.Last;i++){
>    printf("%d ",L.Elements[i]);
>}
>```
></td>
><td>  2 4 6 8 10 </td>
></tr>
><tr>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void sort(List* pL) {
>	for (Position P = 1; P < pL->Last + 1; P++)
>		for (Position Q = P + 1; Q < pL->Last + 1; Q++)
>			if (pL->Elements[P - 1] > pL->Elements[Q - 1]) {
>				ElementType tmp = pL->Elements[P - 1];
>				pL->Elements[P - 1] = pL->Elements[Q - 1];
>				pL->Elements[Q - 1] = tmp;
>			}
>}
> ```


##
# removeAll
>Cho trước các phép toán sau:
>
>
>- Tìm vị trí xuất hiện đầu tiên của phần tử x trong danh sách **locate()**
>- Xóa phần tử ở vị trí p trong danh sách **deleteList()**
>
>Hãy viết hàm xóa tất cả phần tử có giá trị x trong danh sách đặc các số nguyên.
>
>
>- Tên hàm (function name): **removeAll()**
>- Tham số (parameters):
>   - **x** - kiểu phần tử (là số nguyên)
>   - **pL** - con trỏ kiểu List
>- Kiểu trả về: Không
>
>**Thân hàm (Body)**
>
>- Xóa tất cả phần tử có giá trị là x trong danh sách chỉ bởi con trỏ pL
>
>
>**Chú ý**
>
>- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
>
>
>**Gợi ý**
>
>- Gọi p là vị trí xuất hiện đầu tiên của x trong danh sách. Trong khi p là một vị trí hợp lệ thì xóa phần tử ở vị trí p, rồi lặp lại việc tìm vị trí x trong danh sách
> 
> **For example**
><table>
><tr>
><td> Test </td> <td> Result </td>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>  {  L.Elements[i] = 2*i;}
>L.Last=5;
>removeAll(0,&L);
>for(i=0;i<L.Last;i++)
>{    printf("%d ",L.Elements[i]);}
>```
></td>
><td>  2 4 6 8 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>{    L.Elements[i] = 2*i;}
>L.Elements[i] = 8;
>L.Last=6;
>removeAll(8,&L);
>for(i=0;i<L.Last;i++)
>{    printf("%d ",L.Elements[i]);}
>```
></td>
><td> 0 2 4 6 </td>
></tr>
><tr>
></tr>
><tr>
><td>
>
>```c
>List L;
>int i;
>L.Last=0;
>for(i=0;i<5;i++)
>{    L.Elements[i] = 2*i;}
>L.Elements[i] = 2;
>L.Elements[i+1] = 0;
>L.Elements[i+2] = 2;
>L.Last=8;
>removeAll(2,&L);
>for(i=0;i<L.Last;i++)
>{    printf("%d ",L.Elements[i]);}
>```
></td>
><td>  0 4 6 8 0 </td>
></tr>
></table>
>
> **Answer**
> 
> ```c
>void removeAll(ElementType x, List* pL) {
>	while (locate(x, *pL) != pL->Last + 1) {
>		deleteList(locate(x, *pL), pL);
>	}
>}
> ```
