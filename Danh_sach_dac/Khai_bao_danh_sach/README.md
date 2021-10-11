##
## Khai báo Line
>```c
>#define MaxLenght 80
>
>typedef char ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType Elements[MaxLenght];
>	Position Last;
>}Line;
>```
##
## Khai báo List
>```c
>#define MaxLenght 100
>
>typedef float ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType Elements[MaxLenght];
>	Position Last;
>}List;
>```
##
## Khai báo List SinhVien
>```c
>#define MaxLenght 40
>
>typedef struct {
>	char MSSV[10];
>	char HoTen[50];
>	float DiemLT, DiemTH1, DiemTH2;
>}SinhVien;
>
>typedef SinhVien ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType A[MaxLenght];
>	Position n;
>}List;
>```
##
## Khai báo Polygon
>```c
>#define MaxLenght 100
>
>typedef struct {
>	int x, y;
>}Point;
>
>typedef Point ElementType;
>typedef int Position;
>
>typedef struct {
>	ElementType Elements[MaxLenght];
>	Position n;
>}Polygon;
>```
##
## Khai báo DaThuc
>```c
>#define MaxLenght 100
>
>typedef DonThuc ElementType;
>typedef int Position;
>
>struct DaThuc {
>	ElementType A[MaxLenght];
>	Position so_luong;
>};
>```
