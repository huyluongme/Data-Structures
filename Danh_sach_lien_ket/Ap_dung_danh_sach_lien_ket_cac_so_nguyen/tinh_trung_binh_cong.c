/*
Bằng cách sử dụng những phép toán chuẩn trên danh sách trong thư viện PListLib.c,
hãy viết chương trình cho phép tính trung bình cộng các phần tử trong danh sách
input:
5
2 4 6 8 10
output:
2 4 6 8 10
6.000
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

float getAvg(List L) {
	float result = 0.0;
	int count = 0;
	Position P = first(L), E = endList(L);
	while (P != E) {
		result += retrieve(P, L);
		P = next(P, L);
		count++;
	}
	return result / count;
}

int main() {
	List L;
	makenullList(&L);
	readList(&L);
	printList(L);
	printf("\n%.3f", getAvg(L));
	return 0;
}