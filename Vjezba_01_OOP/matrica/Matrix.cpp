#include <iostream>
#include <iomanip>

using namespace std;

typedef struct matrix{
	float** arr;
	float x, y;
	void unos();
	void ispis();
	void gener();
	void trans(matrix* a, matrix* b);
	void zbroj(matrix* a, matrix* b);
	void oduz(matrix* a, matrix* b);
	void adding(matrix* a, matrix* b);
}matrix;

void matrix::unos()
{
	arr = new float*[x];
	for (int i = 0; i < x; i++)
		arr[i] = new float[y];
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
		{
			cout << "Unesite broj za "<< i + 1<<" red i "<< j + 1 << " stupac:" << endl;
			cin >> arr[i][j];
		}
}

void matrix::ispis()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << fixed << setprecision(2) << arr[i][j] << " ";
		puts(" ");
	}
}

void matrix::gener()
{
	arr = new float* [x];
	for (int i = 0; i < x; i++)
		arr[i] = new float[y];
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = (float(rand()) / float((RAND_MAX)) * 10);
		}
}

void matrix::trans(matrix *a,matrix *b)
{
	a->arr = new float* [x];
	for (int i = 0; i < x; i++)
	{
		a->arr[i] = new float[y];
		for (int j = 0; j < y; j++)
			a->arr[i][j] = b->arr[j][i];
	}
}

void matrix::zbroj(matrix* a, matrix* b)
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			a->arr[i][j] = b->arr[i][j]+a->arr[i][j];
}

void matrix::oduz(matrix* a, matrix* b)
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			a->arr[i][j] = b->arr[i][j] - a->arr[i][j];
}

void matrix::adding(matrix* a, matrix* b)
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			a->arr[i][j] = b->arr[i][j] * a->arr[i][j];
}

void main()
{
	matrix a,b;
	cout << "unestie redke i stupce 1. matrice: " << endl;
	cin >> a.x >> a.y;
	cout << "unesite redke i stupce 2. matrice: " << endl;
	cin >> b.x >> b.y;
	a.unos();
	b.unos();
	//a.gener();
	//a.trans(&a,&b);
	//a.zbroj(&a, &b);
	//a.oduz(&a, &b);
	a.adding(&a, &b);
	a.ispis();
}