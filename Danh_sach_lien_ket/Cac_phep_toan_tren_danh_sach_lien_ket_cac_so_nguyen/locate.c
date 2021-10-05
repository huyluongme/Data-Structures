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

int main()
{
    List L;
    Position p, q;
    ElementType x;

    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;

    p = L;
    q = (struct Node *)malloc(sizeof(struct Node));
    q->Element = 5;
    q->Next = NULL;
    p->Next = q;

    p = p->Next;
    q = (struct Node *)malloc(sizeof(struct Node));
    q->Element = 50;
    q->Next = NULL;
    p->Next = q;

    x = 50;
    q = locate(x, L);
    if (q->Next != NULL)
        printf("Found %d", x);
    else
        printf("Not found %d", x);
    return 0;
}