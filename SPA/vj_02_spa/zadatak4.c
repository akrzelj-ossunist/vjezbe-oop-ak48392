/*Deklarirati strukturu Tocka koja sadrži dva člana: x i y (oba su float). 
Deklarirati strukturu Poligon koja se sadrži dva člana: niz vrhova (svaki vrh u nizu je Tocka) i 
broj vrhova n. Napisati funkcije za rad sa poligonima:

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) – prima niz x i y 
koordinata i stvara novi poligon koji će kao vrhove imati parove brojeva iz 
nizova. Nizovi su dužine n (≥ 3).

Tocka** pozitivni(Poligon *p, int *np) – funkcija vraća niz pokazivača na 
vrhove poligona kojima su obje koordinate pozitivne. Broj elemenata u nizu će 
biti spremljen u np parametar. 

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

Poligon* novi_poligon(Poligon *pol,Poligon *p)
{
	int k = 0;
	Poligon* pol2 = (Poligon*)malloc(p->n * sizeof(Poligon));
	for(int i=0;i<p->n;i++)
		for(int j=i+1;j<p->n;j++)
			if (pol[i].T.x == pol[j].T.x && pol[i].T.y == pol[j].T.y)
			{
				pol2[i].T.x = pol[i].T.x;
				pol2[i].T.y = pol[i].T.y;
				k++;
				break;
			}
	pol2->n = k;
	return pol2;
}

Tocka** pozitivni(Poligon* pol, int* np,Poligon *p)
{
	int k = 0;
	float** pol2 = (float*)malloc(sizeof(float) * p->n);
	for (int i = 0; i < p->n; i++)
	{
		if (pol[i].T.x > 0 && pol[i].T.y > 0)
		{
			pol2[k] = (float*)malloc(sizeof(float));
			pol2[k][0] = pol[i].T.x;
			pol2[k][1] = pol[i].T.y;
			k++;
		}
	}
	*np = k;
	return pol2;
}
int main()
{
	Poligon p;
	int np;
	printf("Unesite duljinu niza: ");
	scanf("%d",&p.n);
	Poligon* pol=(Poligon*)malloc(sizeof(Poligon)*p.n);
	for (int i = 0; i < p.n; i++)
	{
		printf("Unesite %d. tocku: ", i + 1);
		scanf("%f %f", &pol[i].T.x , &pol[i].T.y);
	}

	Poligon* pol2 = novi_poligon(pol,&p);
	for (int i = 0; i < pol2->n; i++)
		printf("%.1f %.1f\n", pol2->T.x,pol2->T.y);

	puts(" ");

	float** pol3 = pozitivni(pol, &np, &p);
	for (int i = 0; i < np; i++)
		printf("%.1f %.1f\n", pol3[i][0], pol3[i][1]);
}*/