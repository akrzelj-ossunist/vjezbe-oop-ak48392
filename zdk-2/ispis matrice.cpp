#include "funkcije.h"
#include <iostream>
#include <iomanip>


using namespace std;

void ispis(float** matrix,float c, float b)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << matrix[i][j] << setprecision(5) << right;
			cout << " ";
		}
		puts(" ");
	}
}