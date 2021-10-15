#include "funkcije.h"
#include <iostream>


using namespace std;


int main()
{
	float a,b;
	float** matz = zbroj(&a,&b);
	//float** matx = oduz();
	//float** matr = mnozenje();
	//float** matt = trans();
	float** matg = gener(a,b);
	ispis(matz,a,b);
	//puts(" ");
	//ispis(matx,a,b);
	//puts(" ");
	//ispis(matr, a, b);
	//puts(" ");
	//ispis(matt, a, b);
	puts(" ");
	ispis(matg, a, b);
}





