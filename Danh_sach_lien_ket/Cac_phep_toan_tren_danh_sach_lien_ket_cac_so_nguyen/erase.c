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

void erase(int x, List *pL)
{
    Position P = locate(x, *pL);
    if (P->Next != NULL)
        deleteList(P, pL);
    else
        printf("Not found %d\n", x);
}

int main()
{
    List L;
    Position p, q;
    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;

    p = L;
    q = (struct Node *)malloc(sizeof(struct Node));
    q->Element = 5;
    q->Next = NULL;
    p->Next = q;

    p = L;

    q = (struct Node *)malloc(sizeof(struct Node));
    q->Element = 500;
    q->Next = p->Next;
    p->Next = q;

    erase(5000, &L);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    return 0;
}