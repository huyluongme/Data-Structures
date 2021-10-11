/*
	Bằng cách sử dụng những phép toán chuẩn trên danh sách,
	hãy viết chương trình cho phép liệt kê các số chẵn và tính trung bình cộng các phần tử là số chẵn trong danh sách
	input:
	5
	2 -1 6 3 10
	output:
	2 -1 6 3 10
	2 6 10
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


void printEvenNum_AVGofEvenNum(List L) {
	float avg = 0.0;
	int count = 0;
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (retrieve(P, L) % 2 == 0) {
			printf("%d ", retrieve(P, L));
			avg += retrieve(P, L);
			count++;
		}
		P = next(P, L);
	}
	printf("\n%.3f", avg / count);
}

int main()
{
	List L;
	readList(&L);
	printList(L);
	printf("\n");
	printEvenNum_AVGofEvenNum(L);
	return 0;
}