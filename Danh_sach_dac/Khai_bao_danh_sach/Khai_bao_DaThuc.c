/* 
    Đa thức là một biểu thức đại số gồm nhiều đơn thức, ví dụ:

2x3+5x2−3x+1 

Như thế, để biểu diễn một đa thức ta cần lưu các đơn thức có trong đa thức này.

Cho cấu trúc DonThuc dùng để lưu trữ một đơn thức đã được khai báo như sau:

typedef struct {
    double he_so;
    int bac;
} DonThuc;
Ta có thể biểu diễn một đa thức bằng một mảng các DonThuc.



Hãy viết khai báo kiểu DaThuc là một danh sách đặc dùng để lưu trữ 1 đa thức gồm các trường:

A: mảng các DonThuc (có thể chứa tối đa 100 đơn thức)
so_luong: số lượng đơn thức có trong đa thức

*/

typedef struct
{
    double he_so;
    int bac;
} DonThuc;

#define Maxlength 100
struct DaThuc
{
    DonThuc A[Maxlength];
    int so_luong;
};
