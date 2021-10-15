/*3. Napisati iterativnu funkciju za traženje najvećeg i najmanjeg broja u nizu.*/

#include "Header.h"
#include <iostream>
#include <iomanip>
void niz(int* i, int* j)
{

	int niz[] = { 2,3,1,4,2,3,6 };
	int max = niz[0], min = niz[0];
	for (int i = 0; i < 7; i++)
	{
		if (max < niz[i])
			max = niz[i];
		if (min > niz[i])
			min = niz[i];
	}
	*i = max;
	*j = min;
}