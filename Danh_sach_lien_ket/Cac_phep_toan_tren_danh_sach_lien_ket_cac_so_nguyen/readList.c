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

void readList(List *pL)
{
    makenullList(pL);
    Position P = *pL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        Position N = (Position)malloc(sizeof(struct Node));
        scanf("%d", &N->Element);
        N->Next = NULL;
        P->Next = N;
        P = P->Next;
    }
}

int main()
{
    List L;
    Position p;
    readList(&L);

    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    return 0;
}