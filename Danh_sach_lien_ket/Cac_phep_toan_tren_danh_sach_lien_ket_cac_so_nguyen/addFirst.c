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

void addFirst(int x, List *pL)
{
    Position P = *pL;
    Position T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}

int main()
{
    List L;
    Position p;

    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;

    addFirst(10, &L);
    addFirst(5, &L);
    addFirst(1, &L);
    addFirst(-10, &L);
    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    printf("\n");
    return 0;
}