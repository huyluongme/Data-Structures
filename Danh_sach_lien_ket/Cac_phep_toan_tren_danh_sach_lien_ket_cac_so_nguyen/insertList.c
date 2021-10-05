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

void insertList(int x, Position p, List *pL)
{
    Position Temp = (Position)malloc(sizeof(struct Node));
    Temp->Element = x;
    Temp->Next = p->Next;
    p->Next = Temp;
}

int main()
{
    List L;
    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;
    Position p = L;
    insertList(5, p, &L);
    p = p->Next;
    insertList(10, p, &L);

    p = L;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    printf("\n");
    return 0;
}