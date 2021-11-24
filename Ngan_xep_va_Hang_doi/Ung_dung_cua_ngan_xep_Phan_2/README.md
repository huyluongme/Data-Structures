#
## ktChuoi
>```c
>int ktChuoi()
>{
>  Stack S;
>  makenullStack(&S);
>  char x[100];
>  fgets(x, 100, stdin);
>  int len = strlen(x);
>  if (x[len - 1] == '\n')
>  	x[len - 1] = '\0';
>  for (int i = 0; i < len; i++)
>  {
>  	if (x[i] == '(')
>  		push('(', &S);
>  	if (x[i] == ')') {
>  		if (!emptyStack(S))
>  			pop(&S);
>  		else
>  			return 0;
>  	}
>  }
>  return emptyStack(S);
>}
>```
#
## tinhGiatri
>```c
>float tinhGiatri(char st[]) {
>  Stack S;
>  float result = 0;
>  makenullStack(&S);
>  int len = strlen(st);
>  for (int i = 0; i < len; i++) {
>  	if (st[i] >= '0' && st[i] <= '9')
>  		push((int)st[i] - (int)'0', &S);
>  	else if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/')
>  	{
>  		result = top(S);
>  		pop(&S);
>  		if (st[i] == '+')
>  			result = top(S) + result;
>  		else if (st[i] == '-')
>  			result = top(S) - result;
>  		else if (st[i] == '*')
>  			result = top(S) * result;
>  		else if (st[i] == '/')
>  			result = top(S) / result;
>  		pop(&S);
>  		push(result, &S);
>  	}
>  }
>  return result;
>}
>```
#
## inThaplucphan
>```c
>void inThaplucphan(int n)
>{
>    char Hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
>    Stack S;
>    makenullStack(&S);
>    while (n != 0)
>    {
>        push(Hex[n % 16], &S);
>        n /= 16;
>    }
>    while (!emptyStack(S))
>    {
>        printf("%c", top(S));
>        pop(&S);
>    }
>}
>```
#
## mucUutien
>```c
>int mucUutien(char op){
>   if (op=='+' || op=='-')
>       return 1;
>   else if (op=='*' || op=='/')
>       return 2;
>}
>```
#
## chuyenHauto
>```c
>void chuyenHauto(char trungto[], char hauto[]) {
>	Stack s;
>	makenullStack(&s);
>	int len = 0;
>	for (int i = 0; i < strlen(trungto); i++) {
>		if ((trungto[i] >= 'a' && trungto[i] <= 'z') || (trungto[i] >= '0' && trungto[i] <= '9')) {
>			hauto[len] = trungto[i];
>			len++;
>		}
>		else if (trungto[i] == '(') {
>			push('(', &s);
>		}
>		else if (trungto[i] == ')') {
>			while (top(s) != '(')
>			{
>				hauto[len] = top(s);
>				pop(&s);
>				len++;
>			}
>			pop(&s);
>		}
>		else if (trungto[i] == '+' || trungto[i] == '-' || trungto[i] == '*' || trungto[i] == '/')
>		{
>			while (!emptyStack(s) && top(s) != '(' && mucUutien(trungto[i]) <= mucUutien(top(s)))
>			{
>				hauto[len] = top(s);
>				pop(&s);
>				len++;
>			}
>			push(trungto[i], &s);
>		}
>
>	}
>
>	while (!emptyStack(s))
>	{
>		hauto[len] = top(s);
>		pop(&s);
>		len++;
>	}
>	hauto[len] = '\0';
>}
>```