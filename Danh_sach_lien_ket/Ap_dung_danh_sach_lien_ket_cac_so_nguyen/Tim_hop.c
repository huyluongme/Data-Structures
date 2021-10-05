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

int member(int x, List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            return 1;
        P = P->Next;
    }
    return 0;
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

List unionSet(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L1;
    while (P->Next != NULL)
    {
        append(P->Next->Element, &L);
        P = P->Next;
    }
    P = L2;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L1))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}


void addFirst(int x, List *pL)
{
    Position P = *pL;
    Position T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}

List readSet()
{
    List L;
    makenullList(&L);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (!member(temp, L))
            addFirst(temp, &L);
    }

    return L;
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
    List L1, L2, L;
    L1 = readSet();
    L2 = readSet();
    printList(L1);
    printf("\n");
    printList(L2);
    L = unionSet(L1, L2);
    printf("\n");
    printList(L);
    return 0;
}