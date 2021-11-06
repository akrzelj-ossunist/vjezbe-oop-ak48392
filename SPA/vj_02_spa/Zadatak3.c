/*int** podijeli(int *niz, int n) – dijeli niz dužine n na dva jednaka dijela
i stvara kopije prvog i drugog dijela. Funkcija vraća dva pokazivača koji 
pokazuju na prvi i na drugi dio.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int** podijeli(int* niz, int n)
{
	int k = 0;
	int** niz2 = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < 2; i++)
	{
		niz2[i] = (int*)malloc(sizeof(int) * n / 2);
		for (int j = 0; j < n / 2; j++)
		{
			niz2[i][j] = niz[k];
			k++;
		}
	}
	return niz2;
}

int main()
{
	int niz[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(niz) / 4;
	int** niz2 = podijeli(niz, n);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
			printf("%d\t", niz2[i][j]);
		puts(" ");
	}
}*/