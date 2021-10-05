#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Student
{
    char ID[10];
    char Name[50];
    float R1, R2, R3;
};

struct Node
{
    struct Student Element;
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

List readList()
{
    List L = getList();
    Position P = L;
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        Position N = (struct Node *)malloc(sizeof(struct Node));
        fgets(N->Element.ID, 10, stdin);
        if (N->Element.ID[strlen(N->Element.ID) - 1] == '\n')
            N->Element.ID[strlen(N->Element.ID) - 1] = '\0';

        fgets(N->Element.Name, 50, stdin);
        if (N->Element.Name[strlen(N->Element.Name) - 1] == '\n')
            N->Element.Name[strlen(N->Element.Name) - 1] = '\0';

        scanf("%f%f%f", &N->Element.R1, &N->Element.R2, &N->Element.R3);
        getchar();

        N->Next = NULL;
        P->Next = N;
        P = P->Next;
    }
    return L;
}

void printList(List L)
{
    Position P = L;
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

void showPassedList(List L)
{
    List P = L;
    int stt = 0;
    while (P->Next != NULL)
    {
        if ((P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3 >= 4.0)
        {
            stt++;
            printf(" %1d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",
                   stt, P->Next->Element.ID, P->Next->Element.Name, P->Next->Element.R1, P->Next->Element.R2, P->Next->Element.R3,
                   (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
        }
        P = P->Next;
    }
    printf("%d students in total", stt);
}

int main()
{
    List L = readList();
    printList(L);
    showPassedList(L);
    return 0;
}