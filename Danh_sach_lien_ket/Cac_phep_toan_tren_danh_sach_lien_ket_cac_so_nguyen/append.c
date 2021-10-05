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

int main()
{
    List L;
    Position p;
    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;

    append(1, &L);
    append(5, &L);
    append(10, &L);
    append(-10, &L);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    printf("\n");
    return 0;
}