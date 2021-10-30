##
>Cây tìm kiếm nhị phân mõi khóa là 1 số nguyên được khai báo như sau:
>```c
>struct Node {
>	int Key;
>	struct Node* Left, * Right;
>};
>```
>Cho trước các phép toán:
>
>      - void insertNode(int x, Tree *pT): thêm khóa x vào cây tìm kiếm nhị phân có gốc chỉ bởi con trỏ pT

##
# isEmpty
>Kiểm tra cây có gốc là T có rỗng hay không?
>```c
>int isEmpty(Tree T) {
>	return T == NULL;
>}
>```

##
# initTree
>Khởi tạo và trả về một cây rỗng
>```c
>Tree initTree() {
>	return NULL;
>}
>```

##
# insertNode
>```c
>void insertNode(int x, Tree* pT) {
>	if ((*pT) == NULL) {
>		(*pT) = (struct Node*)malloc(sizeof(struct Node));
>		(*pT)->Key = x;
>		(*pT)->Left = NULL;
>		(*pT)->Right = NULL;
>	}
>	else if (x < (*pT)->Key)
>		insertNode(x, &((*pT)->Left));
>	else if (x > (*pT)->Key)
>		insertNode(x, &((*pT)->Right));
>}
>```

##
# getParent
>Tìm kiếm nút cha của nút có khóa x trong cây tìm kiếm nhị phân
>```c
>Tree getParent(int x, Tree T) {
>	if (T == NULL) return NULL;
>	if ((T->Left != NULL && T->Left->Key == x) || (T->Right != NULL && T->Right->Key == x)) return T;
>	return (x < T->Key ? getParent(x, T->Left) : getParent(x, T->Right));
>}
>```

##
# rightSibling
>Tìm kiếm nút anh em ruột phải của nút có khóa x trong cây tìm kiếm nhị phân
>```c
>Tree rightSibling(int x, Tree T) {
>	Tree N = getParent(x, T);
>	if (N == NULL)
>		return NULL;
>	return N->Right;
>}
>```

##
# deleteMin
>```c
>int deleteMin(Tree* pT) {
>	int k;
>	if ((*pT)->Left == NULL) {
>		k = (*pT)->Key;
>		(*pT) = (*pT)->Right;
>		return k;
>	}
>	else
>		return deleteMin(&(*pT)->Left);
>}
>```

##
# deleteNode
>Xóa một nút có khóa là x trong cây tìm kiếm nhị phân
>```c
>void deleteNode(int x, Tree* pT) {
>	if ((*pT) != NULL)
>		if (x < (*pT)->Key)
>			deleteNode(x, &(*pT)->Left);
>		else if (x > (*pT)->Key)
>			deleteNode(x, &(*pT)->Right);
>		else
>			if ((*pT)->Left == NULL && (*pT)->Right == NULL)
>				(*pT) = NULL;
>			else if ((*pT)->Left == NULL)
>				(*pT) = (*pT)->Right;
>			else if ((*pT)->Right == NULL)
>				(*pT) = (*pT)->Left;
>			else
>				(*pT)->Key = deleteMin(&((*pT)->Right));
>	else
>		return;
>}
>```

##
# getHeight
>Tính chiều cao cây T
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
# hNode
>Tính chiều cao của nút có khóa x trong cây T
>```c
>int hNode(int x, Tree T) {
>	if (T == NULL) return -1;
>	else if (T->Key == x) return getHeight(T);
>	return (x < T->Key ? hNode(x, T->Left) : hNode(x, T->Right));
>}
>```

##
# findMinimum
>```c
>Tree findMinimum(Tree T) {
>	if (T == NULL)
>		return NULL;
>	while (T->Left != NULL) T = T->Left;
>	return T;
>}
>```

##
# findMaximum
>```c
>Tree findMaximum(Tree T) {
>	if (T == NULL)
>		while (T->Right != NULL) T = T->Right;
>	return T;
>}
>```

##
# getNext
>Trả về con trỏ của nút đứng sau nút có khóa x cho trước trong phép duyệt trung tự (giả sử x chắc chắn có trong cây T)
>```c
>Tree getNext(int x, Tree T) {
>	if (T == NULL)
>		return NULL;
>	if (T->Key == x) {
>		if (T->Left == NULL && T->Right == NULL)
>			return NULL;
>		else {
>			if (T->Right != NULL)
>				return findMinimum(T->Right);
>			else
>				return getParent(x, T);
>		}
>	}
>	else {
>		return (x < T->Key ? getNext(x, T->Left) : getNext(x, T->Right));
>	}
>}
>```

##
# nodeMin
>```c
>Tree nodeMin(Tree T) {
>	if (T == NULL) return NULL;
>	if (T->Left == NULL) return T;
>	return nodeMin(T->Left);
>}
>```

##
# getPrevious
>Trả về con trỏ của nút đứng trước nút có khóa x cho trước trong phép duyệt trung tự (giả sử x chắc chắn có trong cây T)
>```c
>Tree getPrevious(int x, Tree T) {
>	if (T == NULL || x == nodeMin(T)->Key) return NULL;
>
>	Tree nNext = getNext(T->Key, T);
>
>	if (nNext != NULL && nNext->Key == x) return T;
>
>	if (T->Key == x)
>		if (T->Left != NULL) return findMaximum(T->Left);
>
>	return (x < T->Key ? getPrevious(x, T->Left) : getPrevious(x, T->Right));
>}
>```

##
# printPath
>Liệt kê (in) các giá trị khóa trên đường đi của việc tìm kiếm một khóa x trong cây tìm kiếm nhị phân
>```c
>void printPath(int x, Tree T) {
>	while (1) {
>		if (T == NULL) {
>			printf("-> Khong thay");
>			break;
>		}
>		else {
>			if (T->Key != x) {
>				printf("%d ", T->Key);
>				if (T->Key > x)
>					T = T->Left;
>				else
>					T = T->Right;
>			}
>			else {
>				printf("%d ", T->Key);
>				printf("-> Tim thay");
>				break;
>			}
>		}
>	}
>}
>```

##
# preOrder
>Duyệt tiền tự cây tìm kiếm nhị phân T
>```c
>void preOrder(Tree T) {
>  if (T != NULL) {
>  	printf("%d ", T->Key);
>  	preOrder(T->Left);
>  	preOrder(T->Right);
>  }
>}
>```

##
# inOrder
>Duyệt trung tự cây tìm kiếm nhị phân T
>```c
>void inOrder(Tree T) {
>  if (T != NULL) {
>  	inOrder(T->Left);
>  	printf("%d ", T->Key);
>  	inOrder(T->Right);
>  }
>}
>```

##
# posOrder
>Duyệt hậu tự cây tìm kiếm nhị phân T
>```c
>void posOrder(Tree T) {
>  if (T != NULL) {
>  	posOrder(T->Left);
>  	posOrder(T->Right);
>  	printf("%d ", T->Key);
>  }
>}
>```

##
# searchNode
>Tìm kiếm khóa x trong cây tìm kiếm nhị phân
>```c
>Tree searchNode(int x, Tree T) {
>	if (T == NULL)
>		return NULL;
>	if (T->Key == x)
>		return T;
>	return (x < T->Key ? searchNode(x, T->Left) : searchNode(x, T->Right));
>}
>```
