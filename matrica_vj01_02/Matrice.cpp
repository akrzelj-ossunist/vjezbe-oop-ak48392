#include <iostream>
#include <iomanip>

using namespace std;
typedef struct {
	float x, y;
}matrix;


float** unos(matrix* a)
{
	int i, j;
	float** matrica = new float* [a->x];
	for (i = 0; i < a->x; i++)
		matrica[i] = new float[a->y];
	for (i = 0; i < a->x; i++)
		for (j = 0; j < a->y; j++)
		{cout << "unesite broj za " << i+1 << ". red i za " << j+1 << ". stupac.\n"; cin >> matrica[i][j];}
	return matrica;
}

void ispis(float** matrica,matrix *a)
{

	for (int i = 0; i < a->x; i++)
	{
		for (int j = 0; j < a->y; j++)
		{
			cout << matrica[i][j] <<fixed<< setprecision(2) << right;
			cout << " ";
		}
		puts(" ");
	}

}

float** zbroj(float** mat1, float** mat2,matrix *a)
{
	float** mat3 = new float* [a->x];
	for (int i = 0; i < a->x; i++)
		mat3[i] = new float[a->y];
	for (int i = 0; i < a->x; i++)
	{
		for (int j = 0; j < a->y; j++)
			mat3[i][j] = mat2[i][j] + mat1[i][j];
	}
	return mat3;
}

float** oduz(float** mat1, float** mat2,matrix *a)
{
	float** mat3 = new float* [a->x];
	for (int i = 0; i < a->x; i++)
		mat3[i] = new float[a->y];
	for (int i = 0; i < a->x; i++)
	{
		for (int j = 0; j < a->y; j++)
			mat3[i][j] = mat2[i][j] - mat1[i][j];
	}
	return mat3;
}

float** mnozenje(float** mat1, float** mat2, matrix* a)
{

	float** mat3 = new float* [a->x];
	for (int i = 0; i < a->x; i++)
		mat3[i] = new float[a->y];
	for (int i = 0; i < a->x; i++)
	{
		for (int j = 0; j < a->y; j++)
			mat3[i][j] = mat2[i][j] * mat1[i][j];
	}
	return mat3;
}

float** trans(float** mat1,matrix *a)
{
	float** mat3 = new float* [a->x];
	for (int i = 0; i < a->x; i++)
		mat3[i] = new float[a->y];
	for (int i = 0; i < a->x; i++)
	{
		for (int j = 0; j < a->y; j++)
			mat3[i][j] = mat1[j][i];
	}
	return mat3;
}

float** gener(matrix *a)
{
	float c = 10;
	float** mat3 = new float* [a->x];
	for (int i = 0; i < a->x; i++)
		mat3[i] = new float[a->y];
	for (int i = 0; i < a->x; i++)
	{
		for (int j = 0; j < a->y; j++)
			mat3[i][j] = (float(rand())/float((RAND_MAX)) * c);
	}
	return mat3;
}

int main()
{
	matrix a;
	cout << "Unesite duljinu redaka matrice: ";
	cin >> a.x;
	cout << "Unesite duljinu stupaca matrice: ";
	cin >> a.y;
	float** mat1 = unos(&a);
	float** mat2 = unos(&a);
	puts(" ");
	float** matz = zbroj(mat1, mat2, &a);
	ispis(matz, &a);
	puts(" ");
	float** mato = oduz(mat1, mat2, &a);
	ispis(mato, &a);
	puts(" ");
	float** matm = mnozenje(mat1, mat2, &a);
	ispis(matm, &a);
	puts(" ");
	float** matt = trans(mat1, &a);
	ispis(matt, &a);
	puts(" ");
	float** matg = gener(&a);
	ispis(matg, &a);
}
