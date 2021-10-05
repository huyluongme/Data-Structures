#include <stdio.h>

#define MaxLength 100

typedef int ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int Front, Rear;
}Queue;

void makenullQueue(Queue* pQ) {
	pQ->Front = -1;
	pQ->Rear = -1;
}

int emptyQueue(Queue Q) {
	return Q.Front == -1;
}

int fullQueue(Queue Q) {
	return ((Q.Rear - Q.Front + 1) == MaxLength);
}

ElementType front(Queue Q) {
	return Q.Elements[Q.Front];;
}

void deQueue(Queue* pQ) {
	if (!emptyQueue(*pQ)) {
		if (pQ->Front == pQ->Rear)
			makenullQueue(pQ);
		else pQ->Front = pQ->Front + 1;
	}
}

void enQueue(ElementType x, Queue* pQ) {
	if (!fullQueue(*pQ)) {
		if (emptyQueue(*pQ)) pQ->Front = 0;
		if (pQ->Rear == MaxLength - 1) {
			for (int i = pQ->Front; i <= pQ->Rear; i++)
				pQ->Elements[i - pQ->Front] = pQ->Elements[i];
			pQ->Rear = MaxLength - 1 - pQ->Front;
			pQ->Front = 0;
		}
		pQ->Rear = pQ->Rear + 1;
		pQ->Elements[pQ->Rear] = x;
	}
}

int main()
{
	int n, time = 0, x;
	Queue Q1, Q2;
	makenullQueue(&Q1);
	makenullQueue(&Q2);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		enQueue(x, &Q1);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		enQueue(x, &Q2);
	}

	while (!emptyQueue(Q1) && !emptyQueue(Q2))
	{
		if (front(Q1) != front(Q2))
		{
			enQueue(front(Q1), &Q1);
			deQueue(&Q1);
			time++;
		}
		else {
			deQueue(&Q1);
			deQueue(&Q2);
			time++;
		}
	}
	printf("%d", time);
	return 0;
}
