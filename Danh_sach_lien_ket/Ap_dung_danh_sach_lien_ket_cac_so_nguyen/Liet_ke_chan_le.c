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

void printEven_Odd_Numbers(List L, int mode)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (mode == 0)
        {
            if (P->Next->Element % 2 == 0)
                printf("%d ", P->Next->Element);
        }
        else if (mode == 1)
        {
            if (P->Next->Element % 2 != 0)
                printf("%d ", P->Next->Element);
        }
        P = P->Next;
    }
}

int main()
{
    List L1;
    readList(&L1);
    printList(L1);
    printf("\n");
    printEven_Odd_Numbers(L1, 1);
    printf("\n");
    printEven_Odd_Numbers(L1, 0);
    return 0;
}