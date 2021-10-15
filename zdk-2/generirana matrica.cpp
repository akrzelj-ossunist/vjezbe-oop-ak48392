#include "funkcije.h"
#include <iostream>
#include <iomanip>



using namespace std;

float** gener(float a,float b)
{
	float** mat3 = new float* [a];
	for (int i = 0; i < a; i++)
		mat3[i] = new float[b];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			mat3[i][j] = rand()%10+1;
	}
	return mat3;
}