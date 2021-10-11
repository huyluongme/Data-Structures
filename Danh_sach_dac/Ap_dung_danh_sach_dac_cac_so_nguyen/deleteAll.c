/*
	Bằng cách sử dụng những phép toán chuẩn trên danh sách,
	hãy viết chương trình cho phép xóa tất cả các phần tử x trong danh sách
	input:
	2 6 -10 2 -100
	6 -10 -100
	output:
	2 6 -10 2 -100
	6 -10 -100
	Nộp code trên ELSE: toàn bộ
*/
#include "AListLib.c"

void readList(List* pL) {
	makenullList(pL);
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
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

void deleteAll(ElementType x, List* pL) {
	Position P = locate(x, *pL);
	while (P != endList(*pL)) {
		deleteList(P, pL);
		P = locate(x, *pL);
	}
}

int main()
{
	List L;
	readList(&L);
	int x;
	scanf("%d", &x);
	printList(L);
	deleteAll(x, &L);
	printf("\n");
	printList(L);
	return 0;
}