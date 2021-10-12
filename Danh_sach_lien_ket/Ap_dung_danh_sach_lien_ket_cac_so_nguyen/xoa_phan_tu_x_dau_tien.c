/*
	Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c,
	hãy viết chương trình cho phép xóa phần tử x xuất hiện đầu tiên trong danh sách
	input:
	5
	2 6 -10 2 -100
	2
	output:
	2 6 -10 2 -100
	6 -10 2 -100
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

int main() {
	List L;
	readList(&L);
	int x;
	scanf("%d", &x);
	printList(L);
	Position P = locate(x, L);
	if (P != endList(L))
		deleteList(P, &L);
	printf("\n");
	printList(L);
	return 0;
}