/*
Bằng cách sử dụng những phép toán chuẩn trên danh sách đã cho trong thư viện AListLib.c,
hãy viết chương trình nhập một danh sách từ bàn phím và cho phép xóa phần tử x xuất hiện đầu tiên trong danh sách
input:
5
2 6 -10 2 -100
2
output:
2 6 -10 2 -100
6 -10 2 -100
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

void deleteX(ElementType x, List* pL) {
	Position P = locate(x, *pL);
	if (P != endList(*pL))
		deleteList(P, pL);
}

int main()
{
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