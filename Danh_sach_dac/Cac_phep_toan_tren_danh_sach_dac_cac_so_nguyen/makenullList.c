/*
	output:
	5 0
	Nộp toàn bộ
*/
#define MaxLenght 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLenght];
	Position Last;
}List;

void makenullList(List* pL) {
	pL->Last = 0;
}

int main()
{
	List L;

	L.Last = 5;
	printf("%d ", L.Last);
	makenullList(&L);
	printf("%d ", L.Last);
	return 0;
}