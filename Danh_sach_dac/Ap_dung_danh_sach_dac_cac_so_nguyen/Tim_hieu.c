/* 
    Bằng cách sử dụng những phép toán chuẩn trên danh sách,
    hãy viết chương trình cho phép tìm hiệu của 2 danh sách biểu diễn tập hợp

    Input:
    5
    2 6 -10 2 -100
    3
    3 6 2
    Output:
    2 6 -10 -100
    3 6 2
    -10 -100
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

void insertSet(ElementType x, List *pL)
{
    if (fullList(*pL))
        printf("Danh sach day\n");
    else
    {
        pL->Elements[pL->Last] = x;
        pL->Last++;
    }
}

int member(ElementType x, List L)
{
    for (Position i = 1; i <= L.Last; i++)
    {
        if (L.Elements[i - 1] == x)
            return 1;
    }
    return 0;
}


void readList(List *pL)
{
    makenullList(pL);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (!member(temp, *pL))
            insertSet(temp, pL);
    }
}

void printList(List L)
{
    for (int i = 1; i <= L.Last; i++)
    {
        printf("%d ", L.Elements[i - 1]);
    }
}

void difference(List L1, List L2, List *pL)
{
    makenullList(pL);
    for (int i = 1; i <= L1.Last; i++)
    {
        if (!member(L1.Elements[i - 1], L2))
            insertSet(L1.Elements[i - 1], pL);
    }
}

int main()
{
    List L1, L2, L;
    readList(&L1);
    readList(&L2);
    difference(L1, L2, &L);
    printList(L1);
    printf("\n");
    printList(L2);
    printf("\n");
    printList(L);
    return 0;
}