#include "funkcije.h"
#include <iostream>
#include <iomanip>


using namespace std;

typedef struct{
	float x, y;
}matrica;

float **unos(float *c,float *b)
{
	matrica a;
	cout << "Unesite duljinu redaka matrice: ";
	cin >> a.x;
	cout << "Unesite duljinu stupaca matrice: ";
	cin >> a.y;
	*c = a.x;
	*b = a.y;
	float** matrix =new float* [a.x];

	for (int i = 0; i < a.x; i++)
		matrix[i] = new float[a.y];

	for (int i = 0; i < a.x; i++)
		for (int j = 0; j < a.y; j++)
			cin >> matrix[i][j];

	return matrix;
}