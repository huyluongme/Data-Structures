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

void printList(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        printf("%d ", P->Next->Element);
        P = P->Next;
    }
}

void sort(List *pL)
{
    Position P = *pL;
    while (P->Next != NULL)
    {
        Position Q = P->Next;
        while (Q->Next != NULL)
        {
            if (P->Next->Element > Q->Next->Element)
            {
                int tmp = Q->Next->Element;
                Q->Next->Element = P->Next->Element;
                P->Next->Element = tmp;
            }
            Q = Q->Next;
        }
        P = P->Next;
    }
}

int main()
{
    List L;
    readList(&L);
    printList(L);
    printf("\n");
    sort(&L);
    printList(L);
    return 0;
}