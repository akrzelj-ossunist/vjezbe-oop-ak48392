#include "longnumber.h"

void write_longnum(LongNumber num)
{
	FILE* fp = fopen("new_num.txt", "w+");
	while (num != NULL)
	{
		fprintf(fp, "%d", num->z);
		num = num->next;
	}
}

LongNumber read_longnum(char* fname)
{
	
	LongNumber lst = NULL;
	FILE* fp = fopen(fname, "r");
	char c;
	while ((c=fgetc(fp)) != EOF)
	{
		LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
		novi->z = c - '0';
		novi->next = lst;
		lst = novi;
	}
	lst = reverse(lst);
	return lst;
}

LongNumber reverse(LongNumber num)
{
	LongNumber tmp = NULL;
	while (num != NULL)
	{
		LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
		novi->z = num->z;
		novi->next = tmp;
		tmp = novi;
		num = num->next;
	}
	return tmp;
}

LongNumber add_longnum(LongNumber a, LongNumber b)
{
	a = reverse(a);
	b = reverse(b);
	LongNumber tmp = NULL;
	int rest = 0;
	while (a != NULL && b != NULL)
	{
		LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
		int total = a->z + b->z;
		novi->z = total % 10 + rest;
		rest = total / 10;
		novi->next = tmp;
		tmp = novi;
		a = a->next;
		b = b->next;
	}
	if (a != NULL)
	{
		while (a != NULL) {
			LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
			int total = rest + a->z;
			novi->z = total % 10;
			rest = total / 10;
			novi->next = tmp;
			tmp = novi;
			a = a->next;
		}
	}
	if (b != NULL)
	{
		while (b != NULL) {
			LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
			int total = rest + b->z;
			novi->z = total % 10;
			rest = total / 10;
			novi->next = tmp;
			tmp = novi;
			b = b->next;
		}
	}
	if (rest > 0)
	{
		LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
		novi->z = rest;
		novi->next = tmp;
		tmp = novi;
	}
	write_longnum(tmp);
	return tmp;
}

LongNumber mul_by_digit(LongNumber num, int z)
{
	num = reverse(num);
	LongNumber tmp = NULL;
	int rest = 0;
	while (num != NULL)
	{
		LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
		int total = num->z * z + rest;
		novi->z = total % 10;
		rest = total / 10;
		novi->next = tmp;
		tmp = novi;
		num = num->next;
	}
	if (rest > 0)
	{
		LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
		novi->z = rest;
		novi->next = tmp;
		tmp = novi;
	}
	write_longnum(tmp);
	return tmp;
}

LongNumber mul_by_pow10(LongNumber num, int pow)
{
	if (pow == 0)
		return num;

	num = reverse(num);
	LongNumber tmp = NULL;
	while (pow > 0)
	{
		LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
		novi->z = 0;
		novi->next = tmp;
		tmp = novi;
		pow--;
	}
	while (num != NULL)
	{
		LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
		novi->z = num->z;
		novi->next = tmp;
		tmp = novi;
		num = num->next;
	}
	return tmp;
}

LongNumber mul_longnum(LongNumber a, LongNumber b)
{
	b = reverse(b);
	int pow = 0;
	LongNumber old = NULL;
	while (b != NULL)
	{
		LongNumber novi = (LongNumber)malloc(sizeof(LongNumber));
		novi = mul_by_digit(a, b->z);
		novi = mul_by_pow10(novi, pow);
		//printf("NOVI: \n");
		//print_longnum(novi);
		if (old == NULL)
		{
			old = novi;
			//printf("STARI: \n");
			//print_longnum(old);
		}
		else
		{
			old = add_longnum(old, novi);
			//printf("STARI: \n");
			//print_longnum(old);
		}
		pow++;
		b = b->next;
	}
	write_longnum(old);
	return old;
}

void print_longnum(LongNumber num)
{
	while (num != NULL)
	{
		printf("%d \t", num->z);
		num = num->next;
	}
	puts(" ");
}

void delete_longnum(LongNumber num)
{
	LongNumber temp = num;
	while (num != NULL)
	{
		temp = num;
		num = num->next;
		free(temp);
	}
}