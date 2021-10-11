/*
	Bằng cách sử dụng những phép toán chuẩn trên danh sách,
	hãy viết chương trình cho phép tìm tập hợp hợp của 2 danh sách biểu diễn tập hợp
	input:
	5
	2 6 -10 2 -100
	3
	3 6 2
	output:
	2 6 -10 -100
	3 6 2
	2 6 -10 -100 3
	Nộp code trên ELSE: toàn bộ
*/
#include "AListLib.c"

void readSet(List* pL) {
	makenullList(pL);
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (locate(x, *pL) == endList(*pL))
			insertList(x, endList(*pL), pL);
	}
}

void printList(List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		printf("%d ", retrieve(P, L));
		P = next(P, L);
	}
}

void unionSet(List L1, List L2, List* pL) {
	makenullList(pL);
	Position P = first(L1), E = endList(L1);
	while (P != E) {
		insertList(retrieve(P, L1), endList(*pL), pL);
		P = next(P, L1);
	}
	P = first(L2), E = endList(L2);
	while (P != E) {
		if (locate(retrieve(P, L2), L1) == endList(L1))
			insertList(retrieve(P, L2), endList(*pL), pL);
		P = next(P, L2);
	}
}

int main()
{
	List L1, L2, L;
	readSet(&L1);
	readSet(&L2);
	unionSet(L1, L2, &L);
	printList(L1);
	printf("\n");
	printList(L2);
	printf("\n");
	printList(L);
	return 0;
}