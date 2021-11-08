##
# Khai báo cây AVL
> Cho mô hình một [cây AVL](https://else.ctu.edu.vn/pluginfile.php/33377/mod_resource/content/2/Chuong%204_AVL_hk1_2122_In.pdf) được cài đặt bằng con trỏ như sau:
> ![](https://raw.githubusercontent.com/huyluongme/Data-Structures/main/Cay_tim_kiem_nhi_phan%20-%20Cay_can_bang/Cai_dat_cay_AVL/image.png)
>
> Viết khai báo cho kiểu dữ liệu cây tìm kiếm nhị phân cân bằng về chiều cao AVL với các thành phần được mô tả như trên.
>
>**Answer:**
>```c
>typedef int KeyType;
>
>struct Node {
>	KeyType Key;
>	int Height;
>	struct Node* Left, * Right;
>};
>
>typedef struct Node* AVLTree;
>```

##
# printNLR
>**Answer:**
>```c
>void printNLR(AVLTree T) {
>	if (T != NULL) {
>		printf("(%d - %d); ", T->Key, T->Height);
>		printNLR(T->Left);
>		printNLR(T->Right);
>	}
>}
>```

##
# printLRN
>**Answer:**
>```c
>void printLRN(AVLTree root) {
>	if (root != NULL) {
>		printLRN(root->Left);
>		printLRN(root->Right);
>		printf("(%d - %d); ", root->Key, root->Height);
>	}
>}
>```

##
# max
>**Answer:**
>```c
>int max(int a, int b) {
>	return (a > b ? a : b);
>}
>```

##
# getHeight
>**Answer:**
>```c
>int getHeight(AVLTree T) {
>	if (T == NULL) return -1;
>	int left_height = getHeight(T->Left);
>	int right_height = getHeight(T->Right);
>	return 1 + (left_height > right_height ? left_height : right_height);
>}
>```

##
# getBalance
>**Answer:**
>```c
>int getBalance(AVLTree T) {
>	if (T == NULL) return 0;
>	return getHeight(T->Left) - getHeight(T->Right);
>}
>```

##
# leftRotate
>**Answer:**
>```c
>AVLTree leftRotate(AVLTree node) {
>	AVLTree temp = node->Right;
>
>	node->Right = temp->Left;
>	temp->Left = node;
>
>	node->Height = 1 + max(getHeight(node->Left), getHeight(node->Right));
>	temp->Height = 1 + max(getHeight(temp->Left), getHeight(temp->Right));
>
>	return temp;
>}
>```

##
# rightRotate
>**Answer:**
>```c
>AVLTree rightRotate(AVLTree node) {
>	AVLTree temp = node->Left;
>
>	node->Left = temp->Right;
>	temp->Right = node;
>
>	node->Height = 1 + max(getHeight(node->Left), getHeight(node->Right));
>	temp->Height = 1 + max(getHeight(temp->Left), getHeight(temp->Right));
>
>	return temp;
>}
>```

##
# rightleftRotate
>**Answer:**
>```c
>AVLTree rightleftRotate(AVLTree node) {
>	node->Right = rightRotate(node->Right);
>	return leftRotate(node);
>}
>```

##
# leftrightRotate
>**Answer:**
>```c
>AVLTree leftrightRotate(AVLTree node) {
>	node->Left = leftRotate(node->Left);
>	return rightRotate(node);
>}
>```

##
# insertNode
>**Answer:**
>```c
>AVLTree insertNode(KeyType key, AVLTree root)
>{
>	if (root == NULL) {
>		root = (struct Node*)malloc(sizeof(struct Node));
>		root->Key = key;
>		root->Left = NULL;
>		root->Right = NULL;
>		root->Height = 0;
>		return root;
>	}
>	if (key < root->Key)
>		root->Left = insertNode(key, root->Left);
>	else if (key > root->Key)
>		root->Right = insertNode(key, root->Right);
>	else
>		return root;
>
>	root->Height = 1 + max(getHeight(root->Left), getHeight(root->Right));
>
>	int BalanceFactor = getBalance(root);
>
>	if (BalanceFactor > 1 && key < root->Left->Key)
>		return rightRotate(root);
>
>	if (BalanceFactor < -1 && key > root->Right->Key)
>		return leftRotate(root);
>
>	if (BalanceFactor > 1 && key > root->Left->Key)
>		return leftrightRotate(root);
>
>	if (BalanceFactor < -1 && key < root->Right->Key)
>		return rightleftRotate(root);
>
>	return root;
>}
>```

##
# printLeaves
>**Answer:**
>```c
>void printLeaves(AVLTree root) {
>	if (root != NULL) {
>		if (root->Left == NULL && root->Right == NULL)
>			printf("%d ", root->Key);
>		printLeaves(root->Left);
>		printLeaves(root->Right);
>	}
>}
>```

##
# printHeight
>**Answer:**
>```c
>void printHeight(int height, AVLTree root) {
>	if (root != NULL) {
>		if (getHeight(root) == height)
>			printf("%d ", root->Key);
>		printHeight(height, root->Left);
>		printHeight(height, root->Right);
>	}
>}
>```

##
# isAVL
>**Answer:**
>```c
>int isAVL(AVLTree root) {
>	if (root == NULL) return 1;
>	if (abs(getBalance(root) <= 1 && isAVL(root->Left) && isAVL(root->Right)))
>		return 1;
>	return 0;
>}
>```
