#
## Khai báo đa thức
>```c
>typedef struct {
>	double he_so;
>	int bac;
>} DonThuc;
>
>struct Node {
>	DonThuc e;
>	struct Node* Next;
>};
>
>typedef struct Node* Position;
>typedef Position DaThuc;
>```

#
## khoitao
>```c
>DaThuc khoitao() {
>	DaThuc d = (DaThuc)malloc(sizeof(struct Node));
>	d->Next = NULL;
>	return d;
>}
>```

#
## chenDonThuc
>```C
>void chenDonThuc(DonThuc s, DaThuc* pD) {
>	Position P = (*pD);
>	while (P->Next != NULL) {
>		if (P->Next->e.bac == s.bac) {
>			P->Next->e.he_so += s.he_so;
>			return;
>		}
>		if(P->Next->e.bac < s.bac) {
>			DaThuc T = (DaThuc)malloc(sizeof(struct Node));
>			T->e = s;
>			T->Next = P->Next;
>			P->Next = T;
>			return;
>		}
>		P = P->Next;
>	}
>	DaThuc T = (DaThuc)malloc(sizeof(struct Node));
>	T->e = s;
>	T->Next = P->Next;
>	P->Next = T;
>}
>```

#
## nhapDaThuc
>```c
>DaThuc nhapDaThuc() {
>	DaThuc d = khoitao();
>	int n;
>	scanf("%d", &n);
>	for (int i = 0; i < n; i++) {
>		DonThuc x;
>		scanf("%lf %d", &x.he_so, &x.bac);
>		chenDonThuc(x, &d);
>	}
>	return d;
>}
>```

#
## inDaThuc
>```c
>#include <math.h>
>void inDaThuc(DaThuc d) {
>	Position P = d;
>	while (P->Next != NULL) {
>		printf("%.3lfX^%d", fabs(P->Next->e.he_so), P->Next->e.bac);
>		if (P->Next->Next != NULL) printf(P->Next->Next->e.he_so > 0 ? " + " : " - ");
>		P = P->Next;
>	}
>}
>```

#
## tinhDaoHam
>```c
>DaThuc tinhDaoHam(DaThuc D) {
>	DaThuc result = khoitao();
>	Position P = D;
>	while (P->Next != NULL) {
>		DonThuc e;
>		e.he_so = P->Next->e.he_so * P->Next->e.bac;
>		e.bac = P->Next->e.bac - 1;
>		chenDonThuc(e, &result);
>		P = P->Next;
>	}
>	return result;
>}
>```

#
## nhanDaThuc
>```c
>DaThuc nhanDaThuc(DaThuc D1, DaThuc D2) {
>	DaThuc D = khoitao();
>	Position P = D1, Q;
>	while (P->Next != NULL) {
>		Q = D2;
>		while (Q->Next != NULL) {
>			DonThuc e;
>			e.he_so = P->Next->e.he_so * Q->Next->e.he_so;
>			e.bac = P->Next->e.bac + Q->Next->e.bac;
>			chenDonThuc(e, &D);
>			Q = Q->Next;
>		}
>		P = P->Next;
>	}
>	return D;
>}
>```

#
## congDaThuc
>```c
>DaThuc congDaThuc(DaThuc D1, DaThuc D2) {
>	DaThuc D = khoitao();
>	Position P = D1;
>
>	while (P->Next != NULL) {
>		chenDonThuc(P->Next->e, &D);
>		P = P->Next;
>	}
>
>	P = D2;
>	while (P->Next != NULL) {
>		chenDonThuc(P->Next->e, &D);
>		P = P->Next;
>	}
>	return D;
>}
>```