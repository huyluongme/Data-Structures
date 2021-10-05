void erase(ElementType x, List* pL) {
	deleteList(locate(x, *pL), pL);
}