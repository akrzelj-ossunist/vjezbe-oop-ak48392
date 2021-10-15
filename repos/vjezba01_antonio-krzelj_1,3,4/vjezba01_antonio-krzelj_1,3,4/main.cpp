#include "Header.h"
#include <iostream>
#include <iomanip>
int main()
{
	/*rekurzija
	int niz[] = { 2,3,1,4,2,3,6 };
	int max = niz[0], min = niz[0],j,k,i=6;
	int a=rek(niz, max, min,i,&j,&k);
	std::cout << j << std::endl;
	std::cout << k << std::endl;
	 */


	int min, max;
	niz(&max, &min);
	std::cout << max << std::endl;
	std::cout << min << std::endl;

	//funk();
}