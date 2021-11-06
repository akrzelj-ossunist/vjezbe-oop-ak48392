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
	FILE *fp2 = fopen("bin1.bin", "rb");
	int i;
	int cnt = 0;
	while ((i = fgetc(fp2)) != EOF)
		cnt++;
	fclose(fp2);
	FILE *fp1 = fopen("bin1.bin", "wb");


	printf("%d\n", cnt);
	fseek(fp1, cnt*(sizeof(test)), SEEK_SET);
	fwrite(&t, sizeof(test), 1, fp1);
	fclose(fp1);
	FILE *fp = fopen("bin1.bin", "rb");
	while ((i=fgetc(fp)) != EOF)
	{
		fread(&t, sizeof(test), 1, fp);
		printf("%.1f %.1f \t", t.x, t.y);
	}
	fclose(fp);
}