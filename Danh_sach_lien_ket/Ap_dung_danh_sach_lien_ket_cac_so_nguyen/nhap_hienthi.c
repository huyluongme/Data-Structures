/*
	Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c,
	hãy viết chương trình cho phép nhập và hiển thị một danh sách số nguyên từ bàn phím
	input:
	5
	2 6 -10 2 -100
	output:
	2 6 -10 2 -100
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
	printList(L);
	return 0;
}