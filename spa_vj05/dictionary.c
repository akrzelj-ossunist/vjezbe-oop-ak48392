#include "Header.h"


Dictionary create()
{
	Dictionary dict = NULL;
	return dict;
}

Dictionary add(Dictionary dict, char* str)
{
	int a;
	Dictionary novi = (Dictionary)malloc(sizeof(Dictionary) * 1025);
	novi->word = (char*)malloc(sizeof(char) * 1024);
	strcpy(novi->word, str);
	novi->next = NULL;
	novi->count = 1;

	if (dict == NULL) {
		dict = novi;
		return dict;
	}

	if (dict->next == NULL)
	{
		a = strcmp(novi->word, dict->word);
		if (a > 0)
		{
			dict->next = novi;
			return dict;
		}
		else {
			novi->next = dict;
			return novi;
		}
	}
	else {
		a = strcmp(novi->word, dict->word);
		if (a <= 0) {
			if (a == 0)
			{
				novi->count = dict->count;
				novi->count += 1;
				dict->count += 1;
			}
			novi->next = dict;
			return novi;
		}
	}
	Dictionary temp = dict;
	while (temp->next != NULL)
	{
		a = strcmp(novi->word, temp->next->word);
		if (strcmp(novi->word, temp->next->word) <= 0)
		{
			if (a == 0)
			{
				novi->count = temp->next->count;
				novi->count += 1;
				temp->next->count += 1;
			}
			novi->next = temp->next;
			temp->next = novi;
			return temp;
		}
		temp = temp->next;
	}
	temp->next = novi;
	return dict;
}

Dictionary cnt(Dictionary dict)
{
	Dictionary temp = dict;
	Dictionary temp1 = dict->next;
	while (temp1->next != NULL)
	{
		if (temp->word == temp1->word)
			temp1->count == temp->count;
		temp = temp->next;
		temp1 = temp1->next;
	}
	return dict;
}

int filter(Word* w)
{
	if (w->count >= 5 && w->count <= 10 && strlen(w->word) > 3)
		return 1;
	else
		return 0;
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w))
{
	Dictionary temp = indict;
	Dictionary temp1 = indict->next;


	while (temp1 != NULL)
	{
		printf("%d ", temp1->count);
		int Bool = filter(temp1);
		if (Bool == 0)
		{
			temp->next = temp1->next;
			free(temp1);
			temp1 = temp->next;
		}
		else
		{
			temp1 = temp1->next;
			temp = temp->next;
		}
	}
	int Bool = filter(indict);
	if (Bool == 0)
	{
		temp = indict;
		indict = indict->next;
		free(temp);
	}
	return indict;
}

void print(Dictionary dict)
{
	while (dict != NULL)
	{
		printf("%s %d\n", dict->word,dict->count);
		dict = dict->next;
	}
}

void destroy(Dictionary dict)
{
	dict = NULL;
}