/*1)Napisati program koji od korisnika čita n brojeva u niz i zatim ih sprema u binarnu datoteku (sa fwrite). 
Prije samog niza se sprema broj n. Broj n se isto čita od korisnika prije čitanja samih brojeva niza.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Unesite duljinu niza: ");
	scanf("%d", &n);
	int *arr = (int*)malloc(n * sizeof(int));
	FILE *fp = fopen("bin.bin", "wb");
	for (int i = 0; i < n; i++)
	{
		printf("Unesite %d. clan niza: ", i + 1);
		scanf("%d", &arr[i]);
		fwrite(&arr[i], sizeof(int), 1, fp);
	}

	fclose(fp);
	free(arr);
}*/