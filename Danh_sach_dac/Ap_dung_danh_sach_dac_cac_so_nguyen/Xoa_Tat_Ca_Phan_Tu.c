/*  
    Bằng cách sử dụng những phép toán chuẩn trên danh sách,
    hãy viết chương trình cho phép xóa tất cả các phần tử x trong danh sách

    Input:
    5
    2 6 -10 2 -100
    2
    Output:
    2 6 -10 2 -100
    6 -10 -100
*/

#include <stdio.h>

#define Maxlength 20
typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements [Maxlength];
	int Last;
}List;

void makenullList(List *pL)
{
	(*pL).Last=0;
}

int fullList(List L)
{
	return L.Last==Maxlength;
}

int emptyList(List L)
{
	return L.Last==0;
}

Position first (List L)
{
	return 1;
}

Position endList(List L){
    return L.Last+1;
}

Position next(Position P, List L){
    return P+1;
}

Position previous(Position P, List L){
    return P-1;
}

ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}

void deleteList(Position P, List *L){
    if((P > L->Last) || (P<1))
	printf("\nVi tri khong hop le !!!");
    else
	if(emptyList(*L))
	  printf("\nDanh sach rong !");
	else{
	  Position i;
	  for(i=P; i<L->Last; i++)
	  {
	     L->Elements[i-1] = L-> Elements[i];
	  }
	  L->Last--;
	}
}

Position locate (ElementType x, List L)
{
	Position p=first(L);
	int f=0;
	while (p!=endList(L)&& f==0)
	{
		if (retrieve (p,L)==x)
			f=1;
		else 
			p=next(p,L)	;
	}
	return p;
}


void readList(List* pL) {
	makenullList(pL);
	scanf("%d", &pL->Last);
	for (int i = 1; i <= pL->Last; i++)
	{
		scanf("%d", &pL->Elements[i - 1]);
	}
}

void printList(List L) {
	for (int i = 1; i <= L.Last; i++)
	{
		printf("%d ", L.Elements[i - 1]);
	}
}

void removeAll(ElementType x, List* pL) {
	Position P = 1;
	while (locate(x, *pL) != pL->Last + 1) {
		deleteList(locate(x, *pL), pL);
		P++;
	}
}

int main(){
    List L; int x;
    readList(&L);
    scanf("%d", &x);
    printList(L);
    removeAll(x,&L);
    printf("\n");
    printList(L);
    return 0;
}