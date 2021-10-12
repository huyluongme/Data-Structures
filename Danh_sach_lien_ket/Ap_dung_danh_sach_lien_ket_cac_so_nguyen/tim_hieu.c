/*
	Bằng cách sử dụng những phép toán  trên tập hợp,
	hãy viết chương trình cho phép tìm hiệu của 2 danh sách biểu diễn tập hợp
	input:
	5
	2 6 -10 2 -100
	3
	3 6 2
	output:
	-100 -10 6 2
	2 6 3
	-100 -10
*/
#include "PListLib.c"

int member(ElementType x, List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == x)
			return 1;
		P = next(P, L);
	}
	return 0;
}

void addFirst(ElementType x, List* pL) {
	Position P = *pL;
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}

List readSet() {
	List L;
	makenullList(&L);
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (!member(x, L))
			addFirst(x, &L);
	}
	return L;
}

void printList(List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		printf("%d ", retrieve(P, L));
		P = next(P, L);
	}
}


void defference(List L1, List L2, List* pL) {
	makenullList(pL);
	Position P = first(L1), E = endList(L1);
	while (P != E) {
		if (!member(retrieve(P, L1), L2))
			insertList(retrieve(P, L1), endList(*pL), pL);
		P = next(P, L1);
	}
}

int main() {
	List L1 = readSet(), L2 = readSet();
	List L;
	defference(L1, L2, &L);
	printList(L1);
	printf("\n");
	printList(L2);
	printf("\n");
	printList(L);
	return 0;
}