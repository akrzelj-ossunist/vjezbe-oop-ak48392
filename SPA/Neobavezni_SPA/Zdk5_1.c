/*5)Napisati program koji od korisnika čita dvije koordinate.
Program u datoteku (iz zadatka 3) dodaje još jednu točku na kraj datoteke.
Program zatim čita i ispisuje sve koordinate unazad.
(otvorite datoteku za čitanje i pisanje)*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y;
}test;

int main()
{
	test t;
	printf("Unesite koordinate: ");
	scanf("%f %f", &t.x, &t.y);

	FILE* fp1 = fopen("bin1.bin", "rb+");
	int n;
	fread(&n, 4, 1, fp1);

	fseek(fp1, 0, SEEK_END);
	fwrite(&t, sizeof(test), 1, fp1);

	for (int i = n; i >= 0; i--)
	{
		fseek(fp1, i * (sizeof(test)) + 4, SEEK_SET);
		fread(&t, sizeof(test), 1, fp1);
		printf("%.1f %.1f \t", t.x, t.y);
	}
	puts(" ");
	fclose(fp1);
}