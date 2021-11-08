#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float normal;
	unsigned short collor;
}Triangle;

typedef struct {

	float x1, x2, x3, y1, y2, y3, z1, z2, z3;
}Peak;

typedef struct {
	Triangle* Tr_arr;
	Peak* p;
	unsigned int Tr_number;
}Object_3D;



Object_3D read_binary(char *Header)
{
	FILE* fp = fopen("primjerbin.stl", "rb");
	
	fread(Header, 80, 1, fp);
	Object_3D O;
	fread(&O.Tr_number, sizeof(unsigned int), 1, fp);
	printf("%d", O.Tr_number);
	O.Tr_arr = (Triangle*)malloc(O.Tr_number * sizeof(float) * 3);
	O.p = (Peak*)malloc(O.Tr_number * sizeof(float) * 9);
	for (int cnt = 0; cnt != O.Tr_number; cnt++)
	{
		fread(&O.Tr_arr[cnt].normal, 4, 1, fp);
		fread(&O.Tr_arr[cnt].normal, 4, 1, fp);
		fread(&O.Tr_arr[cnt].normal, 4, 1, fp);

		fread(&O.p[cnt].x1, 4, 1, fp);
		fread(&O.p[cnt].x2, 4, 1, fp);
		fread(&O.p[cnt].x3, 4, 1, fp);
		fread(&O.p[cnt].y1, 4, 1, fp);
		fread(&O.p[cnt].y2, 4, 1, fp);
		fread(&O.p[cnt].y3, 4, 1, fp);
		fread(&O.p[cnt].z1, 4, 1, fp);
		fread(&O.p[cnt].z2, 4, 1, fp);
		fread(&O.p[cnt].z3, 4, 1, fp);

		fread(&O.Tr_arr[cnt].collor, 2, 1, fp);
	}
		
	fclose(fp);
	return O;
}

void write_binary(Object_3D O, char* Header)
{
	FILE* fp = fopen("bin1.stl", "wb");
	fwrite(Header, 80, 1, fp);
	fwrite(&O.Tr_number, sizeof(unsigned int), 1, fp);
	for (int cnt = 0; cnt != O.Tr_number; cnt++)
	{
		fwrite(&O.Tr_arr[cnt].normal, 4, 1, fp);
		fwrite(&O.Tr_arr[cnt].normal, 4, 1, fp);
		fwrite(&O.Tr_arr[cnt].normal, 4, 1, fp);

		fwrite(&O.p[cnt].x1, 4, 1, fp);
		fwrite(&O.p[cnt].x2, 4, 1, fp);
		fwrite(&O.p[cnt].x3, 4, 1, fp);
		fwrite(&O.p[cnt].y1, 4, 1, fp);
		fwrite(&O.p[cnt].y2, 4, 1, fp);
		fwrite(&O.p[cnt].y3, 4, 1, fp);
		fwrite(&O.p[cnt].z1, 4, 1, fp);
		fwrite(&O.p[cnt].z2, 4, 1, fp);
		fwrite(&O.p[cnt].z3, 4, 1, fp);

		fwrite(&O.Tr_arr[cnt].collor, 2, 1, fp);
	}
	fclose(fp);
}

void write_text(Object_3D O)
{
	FILE* fp1 = fopen("bin1txt.stl", "w");
	fprintf(fp1,"solid %s\n","Zaglavlje");
	for (int cnt = 0; cnt != 1404; cnt++)
	{
		fprintf(fp1, "  facet normal %d %d %d\n", O.Tr_arr[cnt].normal, O.Tr_arr[cnt].normal, O.Tr_arr[cnt].normal);
		printf("%d %d %d\n", O.Tr_arr[cnt].normal, O.Tr_arr[cnt].normal, O.Tr_arr[cnt].normal);
		fprintf(fp1, "    outer loop\n");
		fprintf(fp1, "      vertex %.1f %.1f %.1f\n", O.p[cnt].x1, O.p[cnt].x2, O.p[cnt].x3);
		fprintf(fp1, "      vertex %.1f %.1f %.1f\n", O.p[cnt].y1, O.p[cnt].y2, O.p[cnt].y3);
		fprintf(fp1, "      vertex %.1f %.1f %.1f\n", O.p[cnt].z1, O.p[cnt].z2, O.p[cnt].z3);
		fprintf(fp1, "    endloop\n");
		fprintf(fp1, "  endfacet\n");
	}
	fprintf(fp1, "endsolid %s\n", "Zaglavlje");
	fclose(fp1);
}

void delete_struct(Object_3D O)
{
	O.Tr_number = 0;
	free(O.Tr_arr);
	free(O.p);
}

int main()
{
	
	char* Header = (char*)malloc(80);
	Object_3D O = read_binary(Header);
	write_binary(O, Header);
	write_text(O);
	delete_struct(O);
}
