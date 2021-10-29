#include <iostream>
#include <iomanip>

using namespace std;

void index(int* niz, int i, int &br, int len)
{
	for (int j = 0; j < len; j++)
		if (j + 1 == i)
			br = niz[j];
}