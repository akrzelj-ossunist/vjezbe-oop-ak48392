#include <iostream>
#include <iomanip>

using namespace std;

void minimax(int *niz,int &min,int &max,int len)
{
	for (int i = 0; i < len; i++)
	{
		if (niz[i] < min)
			min = niz[i];
		if (niz[i] > max)
			max = niz[i];
	}


}