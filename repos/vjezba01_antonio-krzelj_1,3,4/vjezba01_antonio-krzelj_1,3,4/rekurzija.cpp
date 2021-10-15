/*4. Napisati rekurzivnu funkciju za traženje najvećeg i najmanjeg broja u nizu.*/


#include "Header.h"
#include <iostream>
#include <iomanip>
int rek(int* niz, int max, int min, int i, int* j, int* k)
{
	if (i < 0)
	{
		*j = max;
		*k = min;
		return 0;
	}
	if (max < niz[i])
		max = niz[i];
	if (min > niz[i])
		min = niz[i];
	i--;
	return rek(niz, max, min, i, j, k);
}