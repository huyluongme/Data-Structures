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

Position endList(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
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

void append(ElementType x, List *pL)
{
    Position P = endList(*pL);
    Position T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = NULL;
    P->Next = T;
}

void normalize(List *pL)
{
    Position P = *pL, Q;
    while (P->Next != NULL)
    {
        Q = P->Next;
        while (Q->Next != NULL)
        {
            if (P->Next->Element == Q->Next->Element)
            {
                deleteList(Q, pL);
            }
            else
            {
                Q = Q->Next;
            }
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

    append(1, &L);
    append(-2, &L);
    append(3, &L);
    append(10, &L);
    append(100, &L);
    append(50, &L);

    normalize(&L);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    return 0;
}