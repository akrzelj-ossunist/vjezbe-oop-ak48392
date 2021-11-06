#include <stdio.h>
#include <stdlib.h>

void strlen(char* str,int *len)
{
	for (int i = 0; str[i] != '\0'; i++)
		*len = i+1;
}

void strcpy(char* str, char* str1)
{
	int len;
	strlen(str, &len);
	for (int i = 0; i < len; i++)
		str1[i] = str[i];
	str1[len] = '\0';
}

int strcmpy(char* str, char* str1)
{
	int len, len1;
	strlen(str, &len);
	strlen(str1, &len1);
	if (len > len1)
		return 1;
	if (len < len1)
		return -1;
	for (int i = 0; i < len1; i++)
	{
		if (str[i] > str1[i])
			return 1;
		if (str[i] < str1[i])
			return -1;
	}
	return 0;
}


void strcat(char* str, char* str1)
{
	int len, len1,i,j;
	strlen(str1, &len1);
	strlen(str, &len);
	int lent = len + len1;
	for (i = len, j = 0; i < lent; i++,j++)
		str[i] = str[j];
	str[i] = '\0';
}

void reverse(char* str, char* str1)
{
	int len,i,j;
	strlen(str, &len);
	for (i = len - 1, j = 0; i >= 0; j++, i--)
		str1[j] = str[i];
	str1[j] = '\0';
}

char* strstr(char* str, char* str1)
{
	int len, len1, i, j, br = 0, k;

	strlen(str, &len);
	strlen(str1, &len1);
	for (i = 0; i < len; i++,*str++)
	{
		if (*str == *str1)
			for (k = 0; k < len1;k++)
			{
				if (str[k] == str1[k])
					br++;
			}
		if (br == len1)
			return str;
	}
}

int main()
{
	char str[100] = "Banana";
	char str1[100];
	char str2[100] = "Banana";
	char str3[100] = "ana";
	int len;
	/*strlen(str, &len);
	strcpy(str, str1);
	puts(str1);
    int n=strcmpy(str, str2);
	printf("%d", n);
	strcat(str, str2);
	puts(str);*/
	reverse(str, str1);
	puts(str1);
	//char* str4 = strstr(str, str3);
	//puts(str4);
}
