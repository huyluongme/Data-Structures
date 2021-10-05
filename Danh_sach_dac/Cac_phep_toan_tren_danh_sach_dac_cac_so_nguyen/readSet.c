void readSet(List* pL) {
	makenullList(pL);
	Position tempP;
	scanf("%d", &tempP);
	for (Position i = 0; i < tempP; i++) {
		ElementType tempE;
		scanf("%d", &tempE);
		if (!member(tempE, *pL))
			insertSet(tempE, pL);
	}
}