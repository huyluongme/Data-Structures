/*  
    Hãy viết khai báo cho kiểu dữ liệu List (trong đó Maxlength=100) với các thành phần được mô tả như hình trên để là một danh sách đặc các số thực float
*/

#define Maxlength 100
typedef float ElementType;
typedef int Position;

typedef struct {
	ElementType Elements [Maxlength];
	Position Last;
}List;