/*
	Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c,
	hãy viết chương trình cho phép sắp xếp danh sách tăng dần
	input:
	5
	2 6 -10 2 -100
	output:
	2 6 -10 2 -100
	-100 -10 2 2 6
*/
#include "PListLib.c"

void readList(List* pL) {
	makenullList(pL);
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
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

void sort(List* pL) {
	Position P = first(*pL), E = endList(*pL), Q;
	while (P != E) {
		Q = next(P, *pL);
		while (Q != E) {
			if (retrieve(P, *pL) > retrieve(Q, *pL))
			{
				ElementType x = retrieve(P, *pL), y = retrieve(Q, *pL);
				deleteList(P, pL);
				insertList(y, P, pL);
				deleteList(Q, pL);
				insertList(x, Q, pL);
				E = endList(*pL);
			}
			Q = next(Q, *pL);
		}
		P = next(P, *pL);
	}
}

int main() {
	List L;
	readList(&L);
	printList(L);
	sort(&L);
	printf("\n");
	printList(L);
	return 0;
}