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

void copyEvenNumbers(List L1, List *pL)
{
    makenullList(pL);
    Position P = L1;
    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 == 0)
            append(P->Next->Element, pL);
        P = P->Next;
    }
}

float getAvg(List L)
{
    float S = 0.0f;
    Position P = L;
    int count = 0;
    while (P->Next != NULL)
    {
        S = S + P->Next->Element;
        P = P->Next;
        count++;
    }
    return S / count;
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
    List L1, L;
    readList(&L1);
    printList(L1);
    printf("\n");
    copyEvenNumbers(L1, &L);
    printList(L);
    printf("\n%.3f", getAvg(L));
    return 0;
}