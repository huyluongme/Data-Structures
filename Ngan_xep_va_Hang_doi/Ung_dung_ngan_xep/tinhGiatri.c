#include <stdio.h>
#include <malloc.h>
#include <string.h>
#pragma warning(disable:4996)

typedef float ElementType;
struct Node
{
	ElementType Element;
	struct Node* Next;
};

typedef struct Node* Position;
typedef Position List;

typedef List Stack;

void makenullList(List* pL)
{
	(*pL) = (struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next = NULL;
}

int emptyList(List L)
{
	return L->Next == NULL;
}

Position first(List L) {
	return L;
}

ElementType retrieve(Position P, List L)
{
	if (P->Next != NULL)
		return P->Next->Element;
}

void deleteList(Position P, List* pL)
{
	if (P->Next != NULL)
	{
		Position Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
}

void insertList(float x, Position p, List* pL)
{
	Position Temp = (Position)malloc(sizeof(struct Node));
	Temp->Element = x;
	Temp->Next = p->Next;
	p->Next = Temp;
}

void makenullStack(Stack* pS)
{
	makenullList(pS);
}

int emptyStack(Stack S)
{
	return emptyList(S);
}

ElementType top(Stack S)
{
	return retrieve(first(S), S);
}

void pop(Stack* pS)
{
	deleteList(first(*pS), pS);
}

void push(ElementType x, Stack* pS) {
	insertList(x, first(*pS), pS);
}

void readStack(Stack* pS)
{
	makenullStack(pS);
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		push(x, pS);
	}
}

void printStack(Stack* pS)
{
	while (!emptyStack(*pS))
	{
		printf("%d ", top(*pS));
		pop(pS);
	}
}

float tinhGiatri(char* st)
{
	Stack S;
	float result;
	makenullStack(&S);
	int len = strlen(st);

	for (int i = 0; i < len; i++)
	{
		if (st[i] >= '0' && st[i] <= '9')
			push((int)st[i] - (int)'0', &S);
		else if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/')
		{
			result = top(S);
			pop(&S);
			if (st[i] == '+')
				result = top(S) + result;
			else if (st[i] == '-')
				result = top(S) - result;
			else if (st[i] == '*')
				result = top(S) * result;
			else if (st[i] == '/')
				result = top(S) / result;
			pop(&S);
			push(result, &S);
		}
	}
	return result;
}

int main()
{
	float gt;
	char st[50];
	fgets(st, 50, stdin);
	if (st[strlen(st) - 1] == '\n') {
		st[strlen(st) - 1] = '\0';
	}
	gt = tinhGiatri(st);
	printf("%.2f", gt);
	return 0;
}