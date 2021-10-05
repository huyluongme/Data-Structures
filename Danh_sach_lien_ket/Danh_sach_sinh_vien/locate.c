#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char ID[10];
    char Name[50];
    float R1, R2, R3;
} Student;

struct Node
{
    Student Element;
    struct Node *Next;
};

typedef struct Node *Position;
typedef Position List;

List getList()
{
    List L;
    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;
    return L;
}

struct Node *locate(char x[], List L)
{
    struct Node *P = L;
    while (P->Next != NULL)
    {
        if (strcmp(x, P->Next->Element.ID) == 0)
            return P;
        P = P->Next;
    }
    return P;
}

int main()
{
    List L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;
    struct Node *p, *q;

    Student s;

    strcpy(s.ID, "123");
    strcpy(s.Name, "Hai Long");
    s.R1 = 1.2f;
    s.R2 = 5.6f;
    s.R3 = 5.6f;

    p = L;
    q = (struct Node *)malloc(sizeof(struct Node));
    q->Element = s;
    q->Next = NULL;
    p->Next = q;

    p = p->Next;
    strcpy(s.ID, "567");
    strcpy(s.Name, "Minh Bien");
    s.R1 = 1.2f;
    s.R2 = 1.3f;
    s.R3 = 5.6f;

    q = (struct Node *)malloc(sizeof(struct Node));
    q->Element = s;
    q->Next = NULL;
    p->Next = q;

    p = locate("567", L);
    if (p->Next == NULL)
        printf("NOT FOUND 567");
    else
    {
        float R = (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3) / 3;
        printf("FOUND %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", p->Next->Element.ID,
               p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
               p->Next->Element.R3, R);
    }
    return 0;
}