/*Mjerenje vremena izvođenja algoritma (a posteriori)
Preuzeti iduće funkcije sa primjera na predavanjima:
generiraj(n) – generira niz dužine n sa slučajnim elementima (svaki element se pojavljuje samo jednom u nizu)
shuffle(skup) – miješa elemente u nizu skup
Napisati iduće funkcije:
presjek(skupA, skupB) – funkcija računa presjek dva skupa
presjek_jedan_sortiran(skupA, skupB) – funkcija računa presjek dva skupa, gdje je skupB sortirani niz tako da se funkcija oslanja na upotrebu upotrebom bsearch() funkcije (iz stdlib.h)
presjek_oba_sortirana(skupA, skupB) – funkcija računa presjek dva skupa, gdje je su oba skupa sortirana i moguće je samo ići unaprijed sa indeksima po oba skupa
Skupovi su predstavljeni dinamički alociranim nizovima.
Izmjeriti vrijeme izvođenja svake pojedine funkcije za veličine skupova od 100K do 3M (s korakom 300K) brojeva i nacrtati graf dužina/vrijeme za svaku funkciju.
Oba skupa će imati istu veličinu, ali možda će biti potrebno malo prilagoditi veličine skupova da se dobiju izmjerljiva vremena.
Kod funkcija gdje se skup sortira, u vrijeme izvođenja ulazi i sortiranje drugog niza sa qsort() funkcijom (iz stdlib.h).
Za dužinu (alociranje) niza koji će sadržati presjek nizova se može uzeti veća dužina od dva primljena niza. Nizove koji predstavljaju skupove alocirati i oslobađati za svako mjerenje.
Za mjerenje izvođenja pojedinog algoritma koristiti funkciju clock().
Parametre funkcije proširiti sa dužinom niza.
Za svaku funkciju će se moći ispisati vremena, a graf možete složiti u Excelu.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* generiraj(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 3;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 3;
	}
	return niz;
}

void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

void presjek(int* skupA, int* skupB, int len, int *lenC)
{
	*lenC = 0;
	int* SkupC = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++)
		{
			//if (skupA[i] == skupB[j])
			{
				SkupC[i] = skupA[i] + skupB[j];
				(*lenC) += 1;
			}
		}
	}
	//free(SkupC);
}

int cmpfunc(int* a, int* b) {
	return (*a - *b);
}

void presjek_jedan_sortiran(int* skupA, int* skupB, int len)
{
	for (int i = 0; i < len; i++)
		bsearch(&skupA[i], skupB, len, sizeof(int), cmpfunc);
}

void presjek_oba_sortirana(int* skupA, int* skupB, int len)
{
	for (int i = 0; i < len; i++)
		bsearch(&skupA[i], skupB, len, sizeof(int), cmpfunc);
}

void print(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n\n");
}

void main() {
	srand(time(NULL));

	//printf("NIJEDAN SORTIRAN\n");
	////Presjek oba ne sortirana niza
	//for (int i = 10000; i < 300000; i += 30000) {
	//	int*SkupA = generiraj(i);
	//	int*SkupB = generiraj(i);
	//	shuffle(SkupA, i);
	//	shuffle(SkupB, i);
	//	int lenC = 0;
	//	int start = clock();
	//	presjek(SkupA, SkupB, i, &lenC);
	//	int stop = clock();
	//	double time_taken = (((double)(stop-start)) / CLOCKS_PER_SEC);
	//	printf("For lenght %d program took %lf seconds to execute %d %d %d\n\n", i, time_taken, start, stop, lenC);
	//	free(SkupA);
	//	free(SkupB);
	//}


	printf("JEDAN SORTIRAN\n");
	//Presjek jednog sortiranog drugi nije
	for (int i = 1000000; i < 30000000; i += 3000000)
	{
		int*SkupA = generiraj(i);
		int*SkupB = generiraj(i);
		shuffle(SkupA, i);
		shuffle(SkupB, i);
		qsort(SkupB, i, sizeof(int), cmpfunc);
		int start = clock();
		presjek_jedan_sortiran(SkupA, SkupB, i);
		int stop = clock();
		float time_taken = ((float)(stop - start) / CLOCKS_PER_SEC);
		printf("For lenght %d program took %.4f seconds to execute\n\n", i, time_taken);
		free(SkupA);
		free(SkupB);
	}


	printf("OBA SORTIRANA\n");
	//Presjek oba sortirana niza
	for (int i = 1000000; i < 30000000; i += 3000000)
	{
		int*SkupA = generiraj(i);
		int*SkupB = generiraj(i);
		shuffle(SkupA, i);
		shuffle(SkupB, i);
		qsort(SkupB, i, sizeof(int), cmpfunc);
		qsort(SkupA, i, sizeof(int), cmpfunc);
		int start = clock();
		presjek_oba_sortirana(SkupA, SkupB, i);
		int stop = clock();
		float time_taken = ((float)(stop-start) / CLOCKS_PER_SEC);
		printf("For lenght %d program took %.4f seconds to execute\n\n", i, time_taken);
		free(SkupA);
		free(SkupB);
	}
}