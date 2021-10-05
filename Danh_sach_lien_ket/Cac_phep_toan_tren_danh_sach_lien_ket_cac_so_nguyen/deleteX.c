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

Position locate(int x, List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            return P;
        else
            P = P->Next;
    }
    return P;
}

void deleteList(Position P, List *pL)
{
    if (P->Next != NULL)
    {
        Position Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}

void deleteX(int x, List *pL)
{
    Position P = *pL;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            deleteList(P, pL);
        else
            P = P->Next;
    }
}

int main()
{
    List L;
    Position p, q;
    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;

    p = L;
    q = (struct Node *)malloc(sizeof(struct Node));
    q->Element = 5000;
    q->Next = NULL;
    p->Next = q;

    p = L;

    q = (struct Node *)malloc(sizeof(struct Node));
    q->Element = 500;
    q->Next = p->Next;
    p->Next = q;

    removeAll(5, &L);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
}