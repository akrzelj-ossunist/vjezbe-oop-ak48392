/*2)Napisati program koji čita datoteku iz prethodnog zadatka (sa fread) i ispisuje brojeve na ekran.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp = fopen("bin.bin", "rb");
	int n, br;
	fread(&n, 4, 1, fp);
	for (int i = 0; i < n; i++)
	{
		fread(&br, 4, 1, fp);
		printf("%d\t", br);
	}
}*/