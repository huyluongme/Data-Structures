##
# createTree
> Dựng một cây nhị phân từ các biểu thức duyệt tiền tự và trung tự
>
>**Answer**
>```c
>int preOrderIndex = 0;
>Tree createTree(char pre[], char in[], int star_in, int end_in) {
>	if (star_in > end_in)
>		return NULL;
>	else if (star_in == end_in) {
>		Tree T = (Tree)malloc(sizeof(struct Node));
>		T->Data = pre[preOrderIndex];
>		preOrderIndex++;
>		T->Left = NULL;
>		T->Right = NULL;
>		return T;
>	}
>	else {
>		Tree T = (Tree)malloc(sizeof(struct Node));
>		T->Data = pre[preOrderIndex];
>		preOrderIndex++;
>		int inOrderIndex = findIndex(T->Data, in, star_in, end_in);
>		T->Left = createTree(pre, in, star_in, inOrderIndex - 1);
>		T->Right = createTree(pre, in, inOrderIndex + 1, end_in);
>		return T;
>	}
>}
>```

##
# findMax
> Tìm giá trị lớn nhất trong cây nhị phân
> 
>**Answer**
>```c
>char findMax(Tree T) {
>	if (!emptyTree(T)) {
>		if (isLeaf(T))
>			return T->Data;
>		char left_max = findMax(leftChild(T));
>		char right_max = findMax(rightChild(T));
>		return left_max > right_max ? left_max : right_max;
>	}
>	else return 0;
>}
>```

##
# findElement
> Xác định xem **x** có là giạ trị của một nút trong cây nhị phân hay không
>
>**Answer**
>```c
>Tree findElement(DataType x, Tree T) {
>	if (emptyTree(T))
>		return NULL;
>	else
>		if (T->Data == x)
>			return T;
>		else {
>			Tree left_Ele = findElement(x, leftChild(T));
>			Tree righte_Ele = findElement(x, rightChild(T));
>			return (left_Ele == NULL && righte_Ele == NULL ? NULL : (left_Ele == NULL ? righte_Ele : left_Ele));
>		}
>}
>```

## 
# getDiameter
>
> Tính đường kính của một cây nhị phân
>
>**Answer**
>```c
>int getDiameter(Tree T, int* diameter)
>{
>	if (emptyTree(T))
>		return 0;
>
>	int left_height = getDiameter(T->Left, diameter);
>	int right_height = getDiameter(T->Right, diameter);
>
>	int max_diameter = left_height + right_height + 1;
>
>	*diameter = max(*diameter, max_diameter);
>
>	return max(left_height, right_height) + 1;
>}
>```

##
# getFullNodes
> Đếm số nút có đủ hai con
>
>**Answer**
>```c
>int getFullNodes(Tree T) {
>	if (emptyTree(T))
>		return 0;
>	else if (T->Left != NULL && T->Right != NULL)
>		return  1 + getFullNodes(leftChild(T)) + getFullNodes(rightChild(T));
>
>	return getFullNodes(leftChild(T)) + getFullNodes(rightChild(T));
>}
>```

##
# convertTree
> Chuyển đổi một cây nhị phân sang cây phản chiếu của nó
>
>**Answer**
>```c
>Tree convertTree(Tree T) {
>	if (T == NULL)
>		return NULL;
>
>	Tree MT = (struct Node*)malloc(sizeof(struct Node));
>	MT->Data = T->Data;
>	MT->Left = convertTree(rightChild(T));
>	MT->Right = convertTree(leftChild(T));
>	return MT;
>}
>```

##
# isMirrors
> Kiểm tra xem hai cây có là phản chiếu của nhau hay không
>
>**Answer**
>```c
>int isMirrors(Tree T1, Tree T2) {
>	if (T1 == NULL && T2 == NULL)
>		return 1;
>	if (T1 == NULL || T2 == NULL)
>		return 0;
>
>	return T1->Data == T2->Data && isMirrors(T1->Left, T2->Right) && isMirrors(T1->Right, T2->Left);
>}
>```

##
# printAllPaths
> Hiển thị tất cả các đường đi (từ nút gốc đến nút lá) và có độ dài đường đi thỏa điều kiện cho trước
>
>**Answer**
>```c
>void printAllPaths(Tree T, int path[], int len, int pathlen)
>{
>	if (T == NULL || len > pathlen + 1)
>		return;
>
>	path[len] = T->Data;
>	len++;
>
>	if (len == pathlen + 1 && isLeaf(T))
>		printArray(path, len);
>
>	printAllPaths(leftChild(T), path, len, pathlen);
>	printAllPaths(rightChild(T), path, len, pathlen);
>}
>```