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

int main()
{
    List L = getList();
    if (L->Next == NULL)
        printf("Created a list!!!");
    else
        printf("Exception!!!");
    return 0;
}