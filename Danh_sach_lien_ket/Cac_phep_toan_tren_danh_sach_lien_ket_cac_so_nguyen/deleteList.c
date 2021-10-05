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

void deleteList(Position P, List *pL)
{
    if (P->Next != NULL)
    {
        Position Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
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
    q->Element = 5;
    q->Next = NULL;
    p->Next = q;

    q = (struct Node *)malloc(sizeof(struct Node));
    q->Element = 50;
    q->Next = p->Next;
    p->Next = q;

    deleteList(q, &L);

    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    printf("\n");
}