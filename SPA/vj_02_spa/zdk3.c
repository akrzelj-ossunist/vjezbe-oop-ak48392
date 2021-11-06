/*Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float).
Deklarirati strukturu Poligon koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i
broj vrhova n. Napisati funkcije za rad sa poligonima:

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – prima niz x i y
koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz
nizova. Nizovi su dužine n (≥ 3).

Tocka** pozitivni(Poligon *p, int *np) – funkcija vraća niz pokazivača na
vrhove poligona kojima su obje koordinate pozitivne. Broj elemenata u nizu će
biti spremljen u np parametar. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {

	float x, y;
}Tocka;

typedef struct {
	Tocka T;
	int n;
}Poligon;

Poligon* novi_poligon(float* niz_x, float* niz_y, int n)
{
	Poligon* pol = (Poligon*)malloc(sizeof(Poligon) * n);
	pol->n = n;
	for (int i = 0; i < n; i++)
	{
		pol[i].T.x = niz_x[i];
		pol[i].T.y = niz_y[i];
	}
	return pol;
}

Tocka** pozitivni(Poligon* pol, int* np)
{
	int k = 0;
	Tocka** pol2 = (Tocka**)malloc(sizeof(Tocka*) * pol->n);
	for (int i = 0; i < pol->n; i++)
	{
		if (pol[i].T.x > 0 && pol[i].T.y > 0)
		{
			pol2[k] = &(pol[i].T);
			k++;
		}
	}
	*np = k;
	return pol2;
}
int main()
{
	int np,n;
	printf("Unesite duljinu niza: ");
	scanf("%d", &n);
	float* niz_x = (float*)malloc(sizeof(float) * n);
	float* niz_y = (float*)malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++)
	{
		printf("Unesite %d. tocku: ", i + 1);
		scanf("%f %f", &niz_x[i], &niz_y[i]);
	}
	Poligon* pol = novi_poligon(niz_x, niz_y, n);
	for (int i = 0; i < pol->n; i++)
		printf("%.1f %.1f\n", pol[i].T.x, pol[i].T.y);

	puts(" ");

	Tocka** pol3 = pozitivni(pol, &np);
	for (int i = 0; i < np; i++)
		printf("%.1f %.1f\n", pol3[i]->x,pol3[i]->y);
}