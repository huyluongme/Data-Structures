/* 
	Bằng cách sử dụng những phép toán chuẩn trên danh sách,
	hãy viết chương trình cho phép liệt kê các số chẵn và tính trung bình cộng
	các phần tử là số chẵn trong danh sách

	Input:
	5
	2 -1 6 3 10
	Output:
	2 -1 6 3 10
	2 6 10
	6.000
*/

#include <stdio.h>

#define Maxlength 20
typedef int ElementType;
typedef int Position;

typedef struct
{
	ElementType Elements[Maxlength];
	int Last;
} List;

void makenullList(List *pL)
{
	(*pL).Last = 0;
}

int fullList(List L)
{
	return L.Last==Maxlength;
}

void insertList(ElementType x, Position p, List *pL)
{
	if (fullList(*pL))
		printf("Danh sach day");	
  	else if ((p<1) || (p>pL->Last+1))
	    printf("Vi tri khong hop le");
	else 
	{
	  Position q;   
	  for(q=pL->Last; q>=p; q--)
		 pL->Elements[q]=pL->Elements[q-1];	  
	  pL->Elements[p-1]=x;	  
	  pL->Last++;
	 }
}

void readList(List *pL)
{
	makenullList(pL);
	scanf("%d", &pL->Last);
	for (int i = 1; i <= pL->Last; i++)
	{
		scanf("%d", &pL->Elements[i - 1]);
	}
}

void printList(List L)
{
	for (int i = 1; i <= L.Last; i++)
	{
		printf("%d ", L.Elements[i - 1]);
	}
}

void copyEvenNumbers(List L1, List *pL)
{
	makenullList(pL);
	for (int i = 0; i < L1.Last; i++)
	{
		if (L1.Elements[i] % 2 == 0)
		{
			insertList(L1.Elements[i], pL->Last + 1, pL);
		}
	}
}

float getAvg(List L)
{
	float result = 0.0f;
	for (Position i = 1; i <= L.Last; i++)
	{
		result += L.Elements[i - 1];
	}
	return result / L.Last;
}

int main()
{
	List L1, L;
	readList(&L1);
	copyEvenNumbers(L1, &L);
	printList(L1);
	printf("\n");
	printList(L);
	printf("\n%.3f", getAvg(L));
	return 0;
}