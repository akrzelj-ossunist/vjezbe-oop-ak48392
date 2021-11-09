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
	//3. zdk /////////////////////////////////////////////
	int nt;
	printf("Unesite koliko struktura zelite spremiti: ");
	scanf("%d", &nt);
	FILE* fp4 = fopen("bin1.bin", "wb");
	test T;
	fwrite(&nt, 4, 1, fp4);
	for (int i = 0; i < nt; i++)
	{
		printf("Unesite koordinate: ");
		scanf("%f %f", &T.x, &T.y);
		fwrite(&T, sizeof(test), 1, fp4);
	}
	fclose(fp4);
	//////////////////////////////////////////////////////


	test t;
	printf("Unesite koordinate: ");
	scanf("%f %f", &t.x, &t.y);

	FILE* fp1 = fopen("bin1.bin", "rb");
	int n;
	fread(&n, 4, 1, fp1);
	fclose(fp1);

	FILE* fp = fopen("bin1.bin", "wb");
	fseek(fp, 0, SEEK_END);
	fwrite(&t, sizeof(test), 1, fp);
	fclose(fp);

	FILE* fp2 = fopen("bin1.bin", "rb");
	for (int i = n; i >= 0; i--)
	{
		fseek(fp2, (-i * (sizeof(test))), SEEK_END);
		fread(&t, sizeof(test), 1, fp2);
		printf("%.1f %.1f \t", t.x, t.y);
	}
	puts(" ");
	fclose(fp2);
}