void unionSet(List L1, List L2, List* pL) {
	makenullList(pL);
	for (Position i = 1; i <= L1.Last; i++)
	{
		insertSet(L1.Elements[i - 1], pL);
	}
	for (Position i = 1; i <= L2.Last; i++)
	{
		if (!member(L2.Elements[i - 1], L1))
			insertSet(L2.Elements[i - 1],pL);
	}
}