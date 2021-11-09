/*3)Napisati program koji od korisnika čita n struktura u niz i zatim ih sprema u binarnu datoteku.
Prije samog niza se sprema broj n. Broj n se isto čita od korisnika prije čitanja struktura.
Strukture su tipa Koordinata i sastoje se od dva float broja.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {

	float x, y;
}test;


int main()
{
	int n;
	printf("Unesite koliko struktura zelite spremiti: ");
	scanf("%d", &n);
	FILE* fp = fopen("bin1.bin", "wb");
	test T;
	fwrite(&n, 4, 1, fp);
	for (int i = 0; i < n; i++)
	{
		printf("Unesite koordinate: ");
		scanf("%f %f", &T.x, &T.y);
		fwrite(&T, sizeof(test), 1, fp);
	}
	fclose(fp);
}*/