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

int main()
{
    List L;
    makenullList(&L);
    if (L->Next == NULL)
        printf("A null list");
    else
        printf("Not a null list");
    return 0;
}