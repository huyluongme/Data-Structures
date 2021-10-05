#include <stdio.h>
#include <malloc.h>

typedef struct
{
    double he_so;
    int bac;
} DonThuc;

struct Node
{
    DonThuc e;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position DaThuc;

DaThuc khoitao()
{
    DaThuc D = (struct Node*)malloc(sizeof(struct Node));
    D->Next = NULL;
    return D;
}

int main()
{
    DaThuc d;
    d = khoitao();
    if (d->Next == NULL)
        printf("Da khoi tao");
    else
        printf("Chua khoi tao");
    return 0;
}