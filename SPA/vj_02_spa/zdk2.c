/*int* filtriraj(int* niz, int n, int th, int* nth) – vraća novi niz koji sadrži
brojeve iz originalnog niza koji su manji od th. Originalni niz ima dužinu n. 
Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* filtriraj(int* niz, int n, int th, int* nth)
{
	int i,j;
	int* niz1 = (int*)malloc(n * sizeof(int));
	for(j=0,i=0;i<n;i++)
		if (th > niz[i])
		{
			niz1[j] = niz[i];
			j++;
		}
	*nth = j;
	return niz1;
}

int main()
{
	int th,nth;
	int niz[] = { 1,2,3,4,5,6,7,8 };
	int n = sizeof(niz) / sizeof(int);
	printf("unesite broj za koji ce se gledat manji: ");
	scanf("%d", &th);
	int* niz1 = filtriraj(niz, n, th, &nth);
	for (int i = 0; i < nth; i++)
		printf("%d\t", niz[i]);
}*/