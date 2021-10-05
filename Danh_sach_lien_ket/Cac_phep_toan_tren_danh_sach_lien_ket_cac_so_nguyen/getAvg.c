#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position;
typedef Position List;

void append(int x, List *pL)
{
    Position P = *pL;
    while (P->Next != NULL)
    {
        P = P->Next;
    }
    Position T;
    T = (struct Node *)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = NULL;
    P->Next = T;
}

float getAvg(List L)
{
    if (L->Next != NULL)
    {
        float S = 0.0f;
        Position P = L;
        int count = 0;
        while (P->Next != NULL)
        {
            S = S + P->Next->Element;
            P = P->Next;
            count++;
        }
        return S / count;
    }
    else
    {
        return -10000.000;
    }
}

int main()
{
    List L;
    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;

    append(20, &L);
    append(21, &L);
    append(-5, &L);
    append(10, &L);
    append(-50, &L);

    printf("AVG = %.3f", getAvg(L));
    return 0;
}