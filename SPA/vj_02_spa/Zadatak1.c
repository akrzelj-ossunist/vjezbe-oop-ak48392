/*#include <stdio.h>
#include <stdlib.h>


int* podniz(int* niz, int start, int stop, int len)
{
	int i, j;
	int* niz1 = (int*)malloc((stop - start) * sizeof(int));
	for (i = 0; i < len; i++)
	{
		if (i + 1 == start)
			for (j = 0; j < (stop - start); j++, i++)
			{
				niz1[j] = niz[i];
			}
	}
	return niz1;
}

void main()
{
	int start, stop, len;
	int niz[] = { 1,2,3,4,5,6,7,8 };
	len = sizeof(niz) / sizeof(int);
	printf("Unesite start i stop indeksa: ");
	scanf("%d %d", &start, &stop);
	int* niz1 = podniz(niz, start, stop, len);
	puts(" ");
	for (int i = 1; i < stop - start; i++)
		printf("%d\t", niz1[i]);
	puts(" ");

}
*/