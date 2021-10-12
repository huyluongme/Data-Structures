/*
	input:
	5
	10 8 10 5 7
	10
	output:
	8 5 7
*/

Position locate(ElementType x, List L) {
	Position P = first(L), E = endList(L);
	while (P != E) {
		if (retrieve(P, L) == x)
			return P;
		else
			P = next(P, L);
	}
	return P;
}

void deleteX(ElementType x, List* pL) {
	Position P = locate(x, *pL), E = endList(*pL);
	while (P != E) {
		deleteList(P, pL);
		P = locate(x, *pL);
		E = endList(*pL)
	}
}
