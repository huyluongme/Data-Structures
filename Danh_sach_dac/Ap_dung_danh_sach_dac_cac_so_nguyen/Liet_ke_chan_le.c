/*
	Bằng cách sử dụng những phép toán chuẩn trên danh sách,
	hãy viết chương trình cho phép liệt kê các số lẻ, số chẵn trong danh sách
	Input:
	5
	3 6 -11 2 -100
	Output:
	5
	1 6 6 9 6
*/
#include <stdio.h>

#define Maxlength 20
typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[Maxlength];
	int Last;
}List;

void makenullList(List* pL)
{
	(*pL).Last = 0;

}

void readList(List* pL) {
	makenullList(pL);
	scanf("%d", &pL->Last);
	for (int i = 1; i <= pL->Last; i++)
	{
		scanf("%d", &pL->Elements[i - 1]);
	}
}

void printList(List L) {
	for (int i = 1; i <= L.Last; i++)
	{
		printf("%d ", L.Elements[i - 1]);
	}
}

void print_Even_Odd_Nums(List L, int type_num) {
	for (int i = 1; i <= L.Last; i++)
	{
		if (type_num == 0) {
			if (L.Elements[i - 1] % 2 != 0)
				printf("%d ", L.Elements[i - 1]);
		}
		else{
			if (L.Elements[i - 1] % 2 == 0)
				printf("%d ", L.Elements[i - 1]);
		}
	}
}

int main() {
	List L;
	readList(&L);
	printList(L);
	printf("\n");
	print_Even_Odd_Nums(L, 0);
	printf("\n");
	print_Even_Odd_Nums(L, 1);
	return 0;
}