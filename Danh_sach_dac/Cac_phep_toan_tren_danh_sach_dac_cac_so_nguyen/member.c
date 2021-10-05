int member(ElementType x, List L) {
	for (int i = 1; i <= L.Last; i++)
	{
		if (L.Elements[i - 1] == x)
			return 1;
	}
	return 0;
}