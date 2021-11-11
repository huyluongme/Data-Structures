#
## Khai báo ngăn xếp
>```c
>#define SoPhanTu 100
>
>typedef int ElementType;
>
>typedef struct {
>	ElementType DuLieu[SoPhanTu];
>	int Dinh;
>}NganXep;
>```

#
## khoitao
>```c
>void khoitao(NganXep* pS) {
>	pS->Dinh = SoPhanTu;
>}
>```

#
## ktRong
>```C
>int ktRong(NganXep S) {
>	return S.Dinh == SoPhanTu;
>}
>```

#
## ktDay
>```c
>int ktDay(NganXep S) {
>	return S.Dinh == 0;
>}
>```

#
## them
>```c
>void them(int x, NganXep* pS) {
>	if (pS->Dinh > 0) {
>		pS->DuLieu[pS->Dinh - 1] = x;
>		pS->Dinh--;
>	}
>}
>```

#
## xoa
>```c
>void xoa(NganXep* pS) {
>	if (pS->Dinh < SoPhanTu)
>		pS->Dinh++;
>}
>```

#
## giatriDinh
>```c
>int giatriDinh(NganXep S) {
>	return S.DuLieu[S.Dinh];
>}
>```

#
## congDaThuc
>```c
>void hienthi(NganXep* pS) {
>	while (!ktRong(*pS)) {
>		printf("%d ", giatriDinh(*pS));
>		xoa(pS);
>	}
>}
>```