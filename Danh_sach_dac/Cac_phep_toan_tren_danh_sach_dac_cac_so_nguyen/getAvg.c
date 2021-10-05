float getAvg(List L) {
	float result = 0.0f;
	if (emptyList(L) != 0) {
		for (Position i = 1; i <= L.Last; i++) {
			result += L.Elements[i - 1];
		}
		return result / L.Last;
	}
	else
		return -10000.0f;
}