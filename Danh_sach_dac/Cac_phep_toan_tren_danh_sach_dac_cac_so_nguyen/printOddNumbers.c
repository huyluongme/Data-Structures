void printOddNumbers(List L) {
	for (Position i = 1; i <= L.Last; i++)
		if (L.Elements[i - 1] % 2 != 0)
			printf("%d ", L.Elements[i - 1]);
}