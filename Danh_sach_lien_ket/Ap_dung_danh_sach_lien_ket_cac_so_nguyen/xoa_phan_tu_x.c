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

void removeAll(int x, List *pL)
{
    Position P = locate(x, *pL);
    while (P->Next != NULL)
    {
        deleteList(P, pL);
        P = locate(x, *pL);
    }
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

void printList(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        printf("%d ", P->Next->Element);
        P = P->Next;
    }
}


int main()
{
    List L;
    readList(&L);
    int x;
    scanf("%d", &x);
    printList(L);
    printf("\n");
    removeAll(x, &L);
    printList(L);
    return 0;
}