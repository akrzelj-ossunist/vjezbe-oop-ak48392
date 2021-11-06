/*4)Napisati program koji od korisnika čita jedan broj odnosno indeks.
Program iz datoteke iz prethodnog zadatka čita i ispisuje na ekran koordinatu
koja odgovara tom indeksu. (koristite fseek)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y;
}test;

int main()
{
	int index;
	printf("Unesite index: ");
	scanf("%d", &index);
	int i = 0;
	FILE *fp = fopen("bin1.bin", "rb");
	test index1;
	fseek(fp, index*(sizeof(test)), SEEK_SET);
	fread(&index1, sizeof(test), 1, fp);
	printf("%.1f %.1f", index1.x,index1.y);
	fclose(fp);
}*/