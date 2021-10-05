void normalize(List *pL) {
	for (int i = 1; i <= pL->Last; i++)
	{
		for (int j = i + 1; j <= pL->Last; j++)
		{
			if (pL->Elements[i - 1] == pL->Elements[j - 1]) {
				deleteList(j, pL);
				j--;
			}
		}
	}
}