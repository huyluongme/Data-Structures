void removeAll(ElementType x, List* pL) {
	Position P = 1;
	while (locate(x, *pL) != pL->Last + 1) {
		deleteList(locate(x, *pL), pL);
		P++;
	}
}