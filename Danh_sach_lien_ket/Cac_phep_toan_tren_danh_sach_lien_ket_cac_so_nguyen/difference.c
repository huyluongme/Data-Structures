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

void makenullList(List *pL)
{
    (*pL) = (struct Node *)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}

int member(int x, List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            return 1;
        P = P->Next;
    }
    return 0;
}

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

List difference(List L1, List L2)
{
    List result;
    makenullList(&result);
    Position P = L1;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L2))
            append(P->Next->Element, &result);
        P = P->Next;
    }
    return result;
}

int main()
{
    List L1, L2, L;
    int i;

    Position p;
    makenullList(&L1);
    makenullList(&L2);
    for (i = 1; i <= 3; i++)
        append(i, &L1);
    for (i = -1; i <= 2; i++)
        append(i, &L2);
    L = difference(L1, L2);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    return 0;
}