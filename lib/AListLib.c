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

void insertList(ElementType x, Position p, List *pL)
{
	if (fullList(*pL))
		printf("Danh sach day");	
  	else if ((p<1) || (p>pL->Last+1))
	    printf("Vi tri khong hop le");
	else 
	{
	  Position q;   
	  for(q=pL->Last; q>=p; q--)
		 pL->Elements[q]=pL->Elements[q-1];	  
	  pL->Elements[p-1]=x;	  
	  pL->Last++;
	 }
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
