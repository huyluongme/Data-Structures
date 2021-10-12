/*
	Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c,
	hãy viết chương trình cho phép xóa phần tử x xuất hiện đầu tiên trong danh sách
	input:
	5
	2 6 -10 2 -100
	2
	output:
	2 6 -10 2 -100
	6 -10 -100
*/
#include "PListLib.c"

void deleteX(ElementType x, List* pL) {
	Position P = locate(x, *pL), E = endList(*pL);
	while (P != E) {
		deleteList(P, pL);
		P = locate(x, *pL);
		E = endList(*pL);
	}
}


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

int main() {
	List L;
	readList(&L);
	int x;
	scanf("%d", &x);
	printList(L);
	deleteX(x, &L);
	printf("\n");
	printList(L);
	return 0;
}