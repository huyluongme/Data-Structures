#
> Cây nhị phân có giá trị tại mỗi nút là 1 số nguyên được khai báo như sau:
>```c
>struct Node{
>   int Data;
>   struct Node *Left, *Right;
>};
>typedef struct Node* Tree;
>```

##
# createNode
> Tạo một nút có giá trị x
>```c
>Tree createNode(int x){
>   struct Node* N;
>   N=(struct Node*)malloc(sizeof(struct Node));
>   N->Data=x;
>   N->Left=NULL;
>   N->Right=NULL;
>   return N;
>}
>```

##
# initTree
> Khởi tạo và trả về một cây rỗng
>```c
>Tree initTree() {
>   return NULL;
>}
>```

##
# isEmpty
> Kiểm tra cây có gốc là T có rỗng hay không?
>```c
>int isEmpty(Tree T) {
>	return T == NULL;
>}
>```

##
# preOrder
> Duyệt tiền tự cây nhị phân T
>```c
>void preOrder(Tree T) {
>	if (T != NULL) {
>		printf("%d ", T->Data);
>		preOrder(T->Left);
>		preOrder(T->Right);
>	}
>}
>```

##
# inOrder
> Duyệt trung tự cây nhị phân T
>```c
>void inOrder(Tree T) {
>	if (T != NULL) {
>		inOrder(T->Left);
>		printf("%d ", T->Data);
>		inOrder(T->Right);
>	}
>}
>```

##
# postOrder
> Duyệt hậu tự cây nhị phân T
>```c
>void postOrder(Tree T) {
>	if (T != NULL) {
>		postOrder(T->Left);
>		postOrder(T->Right);
>		printf("%d ", T->Data);
>	}
>}
>```

##
# createTree
> Tạo một cây nhị phân từ giá trị x và hai cây con có sẫn l, r
>```c
>Tree createTree(int x, Tree l, Tree r) {
>	Tree T;
>	T = (struct Node*)malloc(sizeof(struct Node));
>	T->Data = x;
>	T->Left = l;
>	T->Right = r;
>	return T;
>}
>```

##
# getHeight
> Tính chiều cao của một cây nhị phân T
>```c
>int getHeight(Tree T) {
>	if (T == NULL) return -1;
>	else {
>		int left_height = getHeight(T->Left);
>		int right_height = getHeight(T->Right);
>		return 1 + (left_height > right_height ? left_height : right_height);
>	}
>}
>```

##
# getLeaves
> Đếm số nút lá của một cây nhị phân T
>```c
>int getLeaves(Tree T) {
>	if (T == NULL) return 0;
>	else if (T->Left == NULL && T->Right == NULL) return 1;
>	else return getLeaves(T->Left) + getLeaves(T->Right);
>}
>```
