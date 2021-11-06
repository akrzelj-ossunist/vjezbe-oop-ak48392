/*2)Napisati program koji čita datoteku iz prethodnog zadatka (sa fread) i ispisuje brojeve na ekran.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("bin.bin", "rb");
	int n=0;
	while ((fgetc(n)) != EOF)
	{
		fread(n, sizeof(int), 1, fp);
		printf("%d\t", n);
	}
}*/