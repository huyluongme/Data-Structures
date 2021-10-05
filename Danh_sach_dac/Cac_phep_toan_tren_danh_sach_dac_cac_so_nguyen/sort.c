void sort(List* pL) {
	for (int i = 1; i < pL->Last + 1; i++)
	{
		for (int j = i + 1; j < pL->Last + 1; j++)
		{
			if (pL->Elements[i - 1] > pL->Elements[j - 1])
			{
				ElementType temp = pL->Elements[i - 1];
				pL->Elements[i - 1] = pL->Elements[j - 1];
				pL->Elements[j - 1] = temp;
			}
		}
	}
}