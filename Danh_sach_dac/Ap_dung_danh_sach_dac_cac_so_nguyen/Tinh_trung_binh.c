/* 
    Bằng cách sử dụng những phép toán chuẩn trên danh sách,
    hãy viết chương trình cho phép tính trung bình cộng các phần tử trong danh sách

    Input:
    5
    2 4 6 8 10
    Output:
    2 4 6 8 10
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

float getAVG(List L)
{
    float result = 0.0f;
    for (int i = 1; i <= L.Last; i++)
    {
        result = result + L.Elements[i - 1];
    }
    return result / L.Last;
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