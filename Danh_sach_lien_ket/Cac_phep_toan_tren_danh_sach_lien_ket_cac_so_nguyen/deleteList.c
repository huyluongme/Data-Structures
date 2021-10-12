/*
	input:
	50
	output: 50
*/
Position next(Position P, List L) {
	return P->Next;
}

void deleteList(Position P, List* pL) {
	if (next(P, *pL) != NULL) {
		Position tmp = P->Next;
		P->Next = tmp->Next;
		free(tmp);
	}
}