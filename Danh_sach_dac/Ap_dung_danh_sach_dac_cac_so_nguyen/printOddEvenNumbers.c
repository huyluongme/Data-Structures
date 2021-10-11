/*
Bằng cách sử dụng những phép toán chuẩn trên danh sách,
hãy viết chương trình cho phép liệt kê các số lẻ, số chẵn trong danh sách
input:
5
3 6 -11 2 -100
output:
3 6 -11 2 -100
3 -11
6 2 -100
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

void printOddEvenNumbers(int numtype, List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (numtype == 0) {
			if (retrieve(P, L) % 2 != 0)
				printf("%d ", retrieve(P, L));
		}
		else if (numtype == 1)
			if (retrieve(P, L) % 2 == 0)
				printf("%d ", retrieve(P, L));
		P = next(P, L);
	}
}

int main()
{
	List L;
	readList(&L);
	printList(L);
	printf("\n");
	printOddEvenNumbers(0, L);
	printf("\n");
	printOddEvenNumbers(1, L);
	return 0;
}