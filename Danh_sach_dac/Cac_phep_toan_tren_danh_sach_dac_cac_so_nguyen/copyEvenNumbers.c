void copyEvenNumbers(List L1, List* pL) {
	makenullList(pL);
	for (int i = 0; i < L1.Last; i++)
	{
		if (L1.Elements[i] % 2 == 0) {
			insertList(L1.Elements[i], pL->Last + 1, pL);
		}
	}
}