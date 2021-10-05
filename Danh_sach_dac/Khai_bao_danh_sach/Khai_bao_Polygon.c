/* 
    Một điểm trong không gian 2 chiều được mô tả là một cấu trúc gồm 2 trường x, y kiểu số nguyên int.

Một đa giác được cấu thành từ nhiều điểm, chẳng hạn đa giác bên dưới được cấu thành từ 6 điểm: A(xA, yA), B(xB,yB), C(xC,yC), D(xD,yD), E(xE,yE), G(xG,yG).
Giả sử người ta biểu diễn một đa giác bằng một danh sách đặc có tối đa là 100 điểm.

Hãy viết khai báo cho kiểu dữ liệu Polygon biểu diễn các đa giác theo mô tả trên.
*/

#define Maxlength 100

typedef struct
{
    int x, y;
} Point;

typedef Point ElementType;
typedef int Position;

typedef struct
{
    ElementType Elements[Maxlength];
    Position Last;
} Polygon;