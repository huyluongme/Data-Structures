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

List readList()
{
    List L = getList();
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        Student s;
        Position N = (struct Node *)malloc(sizeof(struct Node));
        fgets(s.ID, 10, stdin);
        if (s.ID[strlen(s.ID) - 1] == '\n')
            s.ID[strlen(s.ID) - 1] = '\0';

        fgets(s.Name, 50, stdin);
        if (s.Name[strlen(s.Name) - 1] == '\n')
            s.Name[strlen(s.Name) - 1] = '\0';

        scanf("%f%f%f", &s.R1, &s.R2, &s.R3);
        getchar();

        List P = locate(s.ID, L);
        if (P->Next == NULL)
        {
            append(s, &L);
        }
    }
    return L;
}

void printList(List L)
{
    List P = L;
    int stt = 1;
    while (P->Next != NULL)
    {
        printf(" %1d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",
               stt, P->Next->Element.ID, P->Next->Element.Name, P->Next->Element.R1, P->Next->Element.R2, P->Next->Element.R3,
               (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
        P = P->Next;
        stt++;
    }
}

int main()
{
    List L;
    L = readList();
    printList(L);
    return 0;
}