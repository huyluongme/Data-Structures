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

void sort(List *pL)
{
    Position P = *pL;
    while (P->Next != NULL)
    {
        Position Q = P->Next;
        while (Q->Next != NULL)
        {
            if (P->Next->Element > Q->Next->Element)
            {
                int tmp = Q->Next->Element;
                Q->Next->Element = P->Next->Element;
                P->Next->Element = tmp;
            }
            Q = Q->Next;
        }
        P = P->Next;
    }
}

int main()
{
    List L;
    Position p;

    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;
    int i;
    for (i = 5; i >= 1; i--)
        append(2 * i, &L);

    sort(&L);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    return 0;
}