/*
	Bằng cách sử dụng những phép toán chuẩn trên danh sách,
	hãy viết chương trình cho phép tính trung bình cộng các phần tử trong danh sách
	input:
	5
	2 4 6 8 10
	output:
	2 4 6 8 10
	6.000
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

float getAVG(List L) {
	float result = 0.0;
	Position P = first(L), E = endList(L);
	while (P != E) {
		result += retrieve(P, L);
		P = next(P, L);
	}
	return result / (E - 1);
}

int main()
{
	List L;
	readList(&L);
	printList(L);
	printf("\n");
	printf("%.3f", getAVG(L));
	return 0;
}