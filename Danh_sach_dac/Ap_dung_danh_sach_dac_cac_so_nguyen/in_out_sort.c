/* 
    Bằng cách sử dụng những phép toán chuẩn trên danh sách đã cho trong thư viện AListLib.c,
    hãy viết chương trình cho phép sắp xếp danh sách tăng dần

    Input:
    5
    2 6 -10 2 -100
    Output:
    2 6 -10 2 -100
    -100 -10 2 2 6
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

void sort(List *pL)
{
    for (int i = 1; i < pL->Last + 1; i++)
    {
        for (int j = i + 1; j < pL->Last + 1; j++)
        {
            if (pL->Elements[i - 1] > pL->Elements[j - 1])
            {
                ElementType temp = pL->Elements[i - 1];
                pL->Elements[i - 1] = pL->Elements[j - 1];
                pL->Elements[j - 1] = temp;
            }
        }
    }
}

int main()
{
    List L;
    readList(&L);
    printList(L);
    sort(&L);
    printf("\n");
    printList(L);
}