/*
output
0 2 4 6 8
Nộp code trên ELSE: toàn bộ
*/

#define MaxLenght 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLenght];
	Position Last;
}List;