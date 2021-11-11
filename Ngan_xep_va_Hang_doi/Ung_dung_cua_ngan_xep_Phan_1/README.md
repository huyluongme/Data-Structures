#
## doiNhiPhan
>```c
>void hienthi(NganXep* pS) {
>	while (!ktRong(*pS)) {
>		printf("%d ", giatriDinh(*pS));
>		xoa(pS);
>	}
>}
>
>void doiNhiPhan(int n, NganXep* pS) {
>	khoitao(pS);
>	while (n != 0) {
>		them(n % 2, pS);
>		n /= 2;
>	}
>}
>```

#
## readStack_printStack
>```c
>void readStack(Stack* pS)
>{
>	makenullStack(pS);
>	int n, x;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++)
>	{
>		scanf("%d", &x);
>		push(x, pS);
>	}
>}
>
>void printStack(Stack *pS)
>{
>	while (!emptyStack(*pS))
>	{
>		printf("%d ", top(*pS));
>		pop(pS);
>	}
>}
>```

#
## ktChuoi
>```c
>int ktChuoi()
>{
>	Stack S;
>	makenullStack(&S);
>	char x[100];
>	fgets(x, 100, stdin);
>	int len = strlen(x);
>	if (x[len - 1] == '\n')
>		x[len - 1] = '\0';
>	for (int i = 0; i < len; i++)
>	{
>		if (x[i] == '(')
>			push('(', &S);
>		if (x[i] == ')') {
>			if (!emptyStack(S))
>				pop(&S);
>			else
>				return 0;
>		}
>	}
>	return emptyStack(S);
>}
>```

#
## tinhGiatri
>```c
>float tinhGiatri(char st[]) {
>	Stack S;
>	float result = 0;
>	makenullStack(&S);
>	int len = strlen(st);
>	for (int i = 0; i < len; i++) {
>		if (st[i] >= '0' && st[i] <= '9')
>			push((int)st[i] - (int)'0', &S);
>		else if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/')
>		{
>			result = top(S);
>			pop(&S);
>			if (st[i] == '+')
>				result = top(S) + result;
>			else if (st[i] == '-')
>				result = top(S) - result;
>			else if (st[i] == '*')
>				result = top(S) * result;
>			else if (st[i] == '/')
>				result = top(S) / result;
>			pop(&S);
>			push(result, &S);
>		}
>	}
>	return result;
>}
>```