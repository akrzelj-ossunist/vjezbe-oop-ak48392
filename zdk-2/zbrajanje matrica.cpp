#include "funkcije.h"
#include <iostream>
#include <iomanip>



using namespace std;

float** zbroj(float* x, float* y)
{
	float a, b;
	float** mat1 = unos(&a, &b);
	float** mat2 = unos(&a, &b);
	*x = a;
	*y = b;
	float** mat3 = new float* [a];
	for (int i = 0; i < a; i++)
		mat3[i] = new float[b];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			mat3[i][j] = mat2[i][j] + mat1[i][j];
	}
	return mat3;
}