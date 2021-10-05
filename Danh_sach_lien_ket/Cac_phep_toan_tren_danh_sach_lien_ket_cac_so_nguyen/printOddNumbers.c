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

void printOddNumbers(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 != 0)
            printf("%d ", P->Next->Element);
        P = P->Next;
    }
}

int main()
{
    List L;
		
L=(struct Node*)malloc(sizeof(struct Node));	
L->Next=NULL;
	
append(1, &L);
append(10, &L);
append(11, &L);	
	
printOddNumbers(L);
    return 0;
}