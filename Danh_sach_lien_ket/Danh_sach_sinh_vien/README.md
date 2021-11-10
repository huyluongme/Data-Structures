## 
> Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp bằng một danh sách liên kết. Mỗi sinh viên (cấu trúc Student) là một phần tử trong danh sách liên kết có các thông tin: ID (chuỗi 10 ký tự), Name (chuỗi 50 ký tự), điểm thành phần R1, điểm thành phần R2, điểm thành phần R3 (các điểm này có kiểu float). 
> 
> Hình ảnh của danh sách L có dạng như bên dưới
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_lien_ket/Danh_sach_sinh_vien/Dslk.png)

#
## Khai báo danh sách
>```c
>typedef struct {
>	char ID[10];
>	char Name[50];
>	float R1, R2, R3;
>}Student;
>
>typedef Student ElemetType;
>
>struct Node {
>	ElemetType Element;
>	struct Node* Next;
>};
>
>typedef struct Node* Position;
>typedef Position List;
>```
#
>## **Nhớ thêm thư viện string.h để xử lý chuỗi**

#
## getList
>```c
>List getList() {
>	List L = (struct Node*)malloc(sizeof(struct Node));
>	L->Next = NULL;
>	return L;
>}
>```

#
## locate
>```c
>struct Node* locate(char ID[], List L) {
>	List P = L;
>	while (P->Next != NULL) {
>		if (strcmp(P->Next->Element.ID, ID) == 0)
>			return P;
>		P = P->Next;
>	}
>	return P;
>}
>```

#
## append
>```c
>int append(Student s, List* pL) {
>	List P = locate(s.ID, *pL);
>	if (P->Next == NULL) {
>		List T = (struct Node*)malloc(sizeof(struct Node));
>		T->Element = s;
>		T->Next = NULL;
>		P->Next = T;
>		return 1;
>	}
>	return 0;
>}
>```

#
## readList
>```c
>List readList() {
>	List L = getList();
>	int n;
>	scanf("%d%*c", &n);
>	for (int i = 0; i < n; i++) {
>		Student s;
>		fgets(s.ID, sizeof(s.ID), stdin);
>		if (s.ID[strlen(s.ID) - 1] == '\n')
>			s.ID[strlen(s.ID) - 1] = '\0';
>
>		fgets(s.Name, sizeof(s.Name), stdin);
>		if (s.Name[strlen(s.Name) - 1] == '\n')
>			s.Name[strlen(s.Name) - 1] = '\0';
>
>		scanf("%f%f%f%*c", &s.R1, &s.R2, &s.R3);
>
>		List P = locate(s.ID, L);
>		if (P->Next == NULL)
>			append(s, &L);
>		else printf("%s exists\n", s.ID);
>	}
>	return L;
>}
>```

#
## getFailedList
>```c
>List getFailedList(List L) {
>	List result = getList();
>	List P = L;
>	while (P->Next != NULL) {
>		if ((P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3 < 4)
>			append(P->Next->Element, &result);
>		P = P->Next;
>	}
>	return result;
>}
>```

#
## showPassedList
>```c
>void showPassedList(List L) {
>	List P = L;
>	int stt = 0;
>	while (P->Next != NULL) {
>		if ((P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3 >= 4.0) {
>			stt++;
>			printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", stt, P->Next->Element.ID, P->Next->Element.Name
>				, P->Next->Element.R1, P->Next->Element.R2, P->Next->Element.R3
>				, (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
>		}
>		P = P->Next;
>	}
>	printf("%d students in total", stt);
>}
>```

#
## printList
>```c
>void printList(List L) {
>	List P = L;
>	int stt = 0;
>	while (P->Next != NULL) {
>		stt++;
>		printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", stt, P->Next->Element.ID, P->Next->Element.Name
>			, P->Next->Element.R1, P->Next->Element.R2, P->Next->Element.R3
>			, (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
>		P = P->Next;
>	}
>}
>```