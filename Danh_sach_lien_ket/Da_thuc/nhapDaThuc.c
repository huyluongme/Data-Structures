#include <stdio.h>
#include <malloc.h>

#pragma warning(disable : 4996)

typedef struct
{
    double he_so;
    int bac;
} DonThuc;

struct Node
{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;

DaThuc khoitao()
{
    DaThuc D = (struct Node*)malloc(sizeof(struct Node));
    D->Next = NULL;
    return D;
}

void chenDonThuc(DonThuc x, DaThuc *pD)
{
    Position P = *pD;
    while (P->Next != NULL)
    {
        if (P->Next->e.bac == x.bac)
        {
            P->Next->e.he_so = P->Next->e.he_so + x.he_so;
            return;
        }
        if (P->Next->e.bac < x.bac)
        {
            DaThuc T = (struct Node *)malloc(sizeof(struct Node));
            T->e = x;
            T->Next = P->Next;
            P->Next = T;
            return;
        }
        P = P->Next;
    }
    DaThuc T = (struct Node *)malloc(sizeof(struct Node));
    T->e = x;
    T->Next = P->Next;
    P->Next = T;
}

DaThuc nhapDaThuc()
{
    int n;
    scanf("%d", &n);
    DaThuc d = khoitao();
    for (int i = 1; i <= n; i++)
    {
        DonThuc e;
        scanf("%lf %d", &e.he_so, &e.bac);
        chenDonThuc(e, &d);
    }
    return d;
}

void inDaThuc(DaThuc d)
{
    DaThuc P = d;
    while (P->Next != NULL)
    {
        printf("%.3fX^%d", P->Next->e.he_so, P->Next->e.bac);
        if (P->Next->Next != NULL)
            printf(" + ");
        P = P->Next;
    }
}

int main()
{
    DaThuc d1 = nhapDaThuc();
    inDaThuc(d1);
}