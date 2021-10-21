##
> Cho mô hình một danh sách các số nguyên List biểu diễn một tập hợp như sau:
> 
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Danh_sach_lien_ket/Dslk.png)

##
# Khai báo danh sách liên kết
> 
> ```c
>typedef int ElementType;
>
>struct Node {
>	ElementType Element;
>	struct Node* Next;
>};
>
>typedef struct Node* Position;
>typedef Position List;
> ```

##
# makenullList
> 
> ```c
>void makenullList(List* pL) {
>	(*pL) = (struct Node*)malloc(sizeof(struct Node));
>	(*pL)->Next = NULL;
>}
> ```

##
# insertList
> 
> ```c
>void insertList(ElementType x, Position P, List* pL) {
>	Position T = (struct Node*)malloc(sizeof(struct Node));
>	T->Element = x;
>	T->Next = P->Next;
>	P->Next = T;
>}
> ```

##
# deleteList
> 
> ```c
>void deleteList(Position P, List* pL) {
>	if ((*pL)->Next != NULL) {
>		Position T = P->Next;
>		P->Next = T->Next;
>		free(T);
>	}
>}
> ```

##
# locate
> 
> ```c
>Position locate(ElementType x, List L) {
>	Position P = L;
>	while (P->Next != NULL)
>		if (P->Next->Element == x)
>			return P;
>		else
>			P = P->Next;
>	return P;
>}
> ```

##
# member
> 
> ```c
>int member(ElementType x, List L) {
>	Position P = L;
>	while (P->Next != NULL)
>		if (P->Next->Element == x)
>			return 1;
>		else
>			P = P->Next;
>	return 0;
>}
> ```

##
# append
> 
> ```c
>void append(ElementType x, List* pL) {
>	Position P = (*pL);
>	while (P->Next != NULL)
>		P = P->Next;
>
>	Position T = (struct Node*)malloc(sizeof(struct Node));
>	T->Element = x;
>	T->Next = NULL;
>	P->Next = T;
>}
> ```

##
# addFirst
> 
> ```c
>void addFirst(ElementType x, List* pL) {
>	Position P = (struct Node*)malloc(sizeof(struct Node));
>	P->Element = x;
>	P->Next = (*pL)->Next;
>	(*pL)->Next = P;
>}
> ```

##
# readList
> 
> ```c
>void readList(List* pL) {
>	makenullList(pL);
>	Position P = (*pL);
>	int n;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
>		Position T = (struct Node*)malloc(sizeof(struct Node));
>		scanf("%d", &T->Element);
>		T->Next = NULL;
>		P->Next = T;
>		P = P->Next;
>	}
>}
> ```

##
# readSet
> 
> ```c
>List readSet() {
>	List L;
>	ElementType x;
>	makenullList(&L);
>	int n;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
>		scanf("%d", &x);
>		if (!member(x, L))
>			addFirst(x, &L);
>	}
>	return L;
>}
> ```

##
# printOddNumbers
> 
> ```c
>void printOddNumbers(List L) {
>	Position P = L;
>	while (P->Next != NULL) {
>		if (P->Next->Element % 2 != 0)
>			printf("%d ", P->Next->Element);
>		P = P->Next;
>	}
>}
> ```

##
# copyEvenNumbers
> 
> ```c
>void copyEvenNumbers(List L1, List* pL2) {
>	makenullList(pL2);
>	Position P = L1;
>	while (P->Next != NULL) {
>		if (P->Next->Element % 2 == 0)
>			append(P->Next->Element, pL2);
>		P = P->Next;
>	}
>}
> ```

##
# deleteX
> 
> ```c
>void deleteX(ElementType x, List* pL) {
>	Position P = first(*pL), E = endList(*pL);
>	while (P != E) {
>		if (retrieve(P, *pL) == x)
>			deleteList(P, pL);
>		else
>			P = next(P, *pL);
>	}
>}
> ```

##
# getAvg
> 
> ```c
>float getAvg(List L) {
>	if (L->Next == NULL)
>		return -10000.0f;
>	else {
>		float result = 0;
>		int count = 0;
>		Position P = L;
>		while (P->Next != NULL) {
>			result += P->Next->Element;
>			P = P->Next;
>			count++;
>		}
>		return result / count;
>	}
>}
> ```

##
# difference
> 
> ```c
>List difference(List L1, List L2) {
>	List L;
>	makenullList(&L);
>	Position P = L1;
>	while (P->Next != NULL) {
>		if (!member(P->Next->Element, L2))
>			append(P->Next->Element, &L);
>		P = P->Next;
>	}
>	return L;
>}
> ```

##
# erase
> 
> ```c
>void erase(ElementType x, List* pL) {
>	Position P = locate(x, *pL);
>	if (P->Next != NULL)
>		deleteList(P, pL);
>	else
>		printf("Not found %d\n", x);
>}
> ```

##
# intersection
> 
> ```c
>List intersection(List L1, List L2) {
>	List L;
>	makenullList(&L);
>	Position P = L1;
>	while (P->Next != NULL) {
>		if (member(P->Next->Element, L2))
>			append(P->Next->Element, &L);
>		P = P->Next;
>	}
>	return L;
>}
> ```

##
# normalize
> 
> ```c
>void normalize(List* pL) {
>	Position P = (*pL), Q;
>	while (P->Next != NULL) {
>		Q = P->Next;
>		while (Q->Next != NULL) {
>			if (P->Next->Element == Q->Next->Element)
>				deleteList(Q, pL);
>			else
>				Q = Q->Next;
>		}
>		P = P->Next;
>	}
>}
> ```

##
# removeAll
> 
> ```c
>void removeAll(ElementType x, List* pL) {
>	Position P = locate(x, *pL);
>	while (P->Next != NULL) {
>		deleteList(P, pL);
>		P = locate(x, *pL);
>	}
>}
> ```


##
# sort
> 
> ```c
>void sort(List* pL) {
>	Position P = (*pL), Q;
>	while (P->Next != NULL) {
>		Q = P->Next;
>		while (Q->Next != NULL) {
>			if (Q->Next->Element < P->Next->Element) {
>				ElementType tmp = Q->Next->Element;
>				Q->Next->Element = P->Next->Element;
>				P->Next->Element = tmp;
>			}
>			else
>				Q = Q->Next;
>		}
>		P = P->Next;
>	}
>}
> ```

##
# unionSet
> 
> ```c
>List unionSet(List L1, List L2) {
>	List L;
>	makenullList(&L);
>	Position P = L1;
>	while (P->Next != NULL) {
>		append(P->Next->Element, &L);
>		P = P->Next;
>	}
>
>	P = L2;
>	while (P->Next != NULL) {
>		if (!member(P->Next->Element, L1))
>			append(P->Next->Element, &L);
>		P = P->Next;
>	}
>	return L;
>}
> ```