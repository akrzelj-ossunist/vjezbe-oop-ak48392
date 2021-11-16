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
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
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

int* presjek(int* skupA, int* skupB, int len, int *lenC)
{
	int* SkupC = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			if (skupA[i] == skupB[j])
			{
				SkupC[*lenC] = skupA[i];
				*lenC += 1;
			}
		}
	return SkupC;
}

int cmpfunc(int* a, int* b) { //zasto se inace stavlja const void* a ne int!?
	return (*a - *b);
}

int* presjek_jedan_sortiran(int* skupA, int* skupB, int len, int* lenC, clock_t T)
{
	int* SkupC = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++)
	{
		int num = (int*)bsearch(&skupA[i], skupB, len, sizeof(int), cmpfunc);
		if (num != NULL)
		{
			SkupC[*lenC] = skupA[i];
			*lenC += 1;
		}
			
	}
	return SkupC;
}

int* presjek_oba_sortirana(int* skupA, int* skupB, int len, int* lenC, clock_t T)
{
	int* SkupC = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++)
	{
		int num = (int*)bsearch(&skupA[i], skupB, len, sizeof(int), cmpfunc);
		if (num != NULL)
		{
			SkupC[*lenC] = skupA[i];
			*lenC += 1;
		}

	}
	return SkupC;
}

void print(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n\n");
}

void main() {
	clock_t T = clock();
	srand(time(NULL));
	int len;
	printf("Input size of array: \n");
	scanf("%d", &len);

	int* SkupA = generiraj(len);
	shuffle(SkupA, len);
	print(SkupA, len);

	int* SkupB = generiraj(len);
	shuffle(SkupB, len);
	print(SkupB, len);


	//Presjek oba ne sortirana niza
	int lenC = 0;
	int* SkupC = presjek(SkupA, SkupB, len, &lenC);
	print(SkupC, lenC);
	T = clock() - T;
	double time_taken = ((double)T) / CLOCKS_PER_SEC;
	printf("The program took %f seconds to execute\n\n", time_taken);


	//Presjek jednog sortiranog drugi nije
	lenC = 0;
	qsort(SkupB, len, sizeof(int), cmpfunc);
	SkupC = presjek_jedan_sortiran(SkupA, SkupB, len, &lenC, T);
	print(SkupC, lenC);
	T = clock() - T;
	time_taken = ((double)T) / CLOCKS_PER_SEC;
	printf("The program took %f seconds to execute\n\n", time_taken);


    //Presjek oba sortirana niza
	lenC = 0;
	qsort(SkupA, len, sizeof(int), cmpfunc);
	SkupC = presjek_oba_sortirana(SkupA, SkupB, len, &lenC, T);
	print(SkupC, lenC);
	T = clock() - T;
	time_taken = ((double)T) / CLOCKS_PER_SEC;
	printf("The program took %f seconds to execute\n\n", time_taken);

	free(SkupA);
	free(SkupB);
	free(SkupC);
}
