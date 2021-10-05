void insertSet(ElementType x, List* pL) {
	if (fullList(*pL))
		printf("Danh sach day\n");
	else {
		pL->Elements[pL->Last] = x;
		pL->Last++;
	}
}