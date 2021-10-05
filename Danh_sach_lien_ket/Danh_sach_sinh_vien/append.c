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

struct Node *locate(char ID[], List L)
{
    List P = L;
    while (P->Next != NULL)
    {
        if (strcmp(ID, P->Next->Element.ID) == 0)
            return P;
        else
            P = P->Next;
    }
    return P;
}

int append(Student s, List *pL)
{
    List P = locate(s.ID, *pL);
    if (P->Next == NULL)
    {

        List T = (struct Node *)malloc(sizeof(struct Node));
        T->Element = s;
        T->Next = NULL;
        P->Next = T;
        return 1;
    }
    return 0;
}

int main()
{
    List L;
    Student s1 = {"12345", "Hoang Anh Tuan", 5.2, 6.3, 1.0};
    Student s2 = {"25696", "Thai Anh Van", 5.6, 9.2, 4.1};
    Student s3 = {"12345", "Tran Thai Huynh", 5.6, 2.2, 4.1};

    L = (struct Node *)malloc(sizeof(struct Node));
    L->Next = NULL;

    append(s1, &L);
    append(s2, &L);
    append(s3, &L);

    struct Node *p = L;
    while (p->Next != NULL)
    {
        printf("%10s - %50s - %.3f - %.3f - %.3f\n", p->Next->Element.ID,
               p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
               p->Next->Element.R3);

        p = p->Next;
    }
}