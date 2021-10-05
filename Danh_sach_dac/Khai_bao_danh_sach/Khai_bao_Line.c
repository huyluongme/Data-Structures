/* 
    Một dòng văn bản trên màn hình ở chế độ văn bản có tối đa là 80 ký tự. Thực tế tại một thời điểm cụ thể số lượng ký tự trong dòng là không tới 80 nên người ta duy trì một biến số nguyên để giữ số lượng ký tự thực tế trong dòng.

Để biểu diễn 1 dòng văn bản trên màn hình, người ta dùng 1 danh sách đặc mà mỗi phần tử của dòng là 1 ký tự

Ví dụ: 1 dòng văn bản

              Toi di hoc. Ban o nha.

     được ghi nhận như là một danh sách có mô hình như bên dưới
     Hãy viết khai báo cho kiểu dữ liệu dòng văn bản Line (trong đó Số ký tự tối đa = 80) với các thành phần được mô tả như hình trên để là một danh sách đặc các ký tự
*/

#define Maxlength 80
typedef char ElementType;
typedef int Position;

typedef struct {
	ElementType Elements [Maxlength];
	int Last;
}Line;