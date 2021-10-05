/* 
    Hãy viết hàm ElementType maxList(List L)
    trả về giá trị lớn nhất trong các phần tử của danh sách L.
 */
#include <stdio.h>

#define Maxlength 50
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

ElementType maxList(List L)
{
    ElementType max = L.Elements[0];
    for (int i = 2; i <= L.Last; i++)
    {
        if (max < L.Elements[i - 1])
            max = L.Elements[i - 1];
    }
    return max;
}

int main()
{
    List L;
    readList(&L);
    printf("%d", maxList(L));
    return 0;
}