void difference(List L1, List L2, List* pL) {
	makenullList(pL);

	for (Position i = 1; i <= L1.Last; i++) {
		if (!member(L1.Elements[i - 1], L2)) {
			pL->Elements[pL->Last] = L1.Elements[i - 1];
			pL->Last++;
		}
	}
}