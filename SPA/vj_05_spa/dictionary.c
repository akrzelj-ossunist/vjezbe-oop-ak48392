#include "Header.h"


Dictionary create()
{
	Dictionary dict = (Dictionary)malloc(sizeof(Word));
	dict->next = NULL;
	dict->word = NULL;
	return dict;
}

void add(Dictionary dict, char* str)
{
	Dictionary temp = dict;
	Dictionary temp1 = dict->next;

	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(novi->word, str);
	novi->count = 1;

	while (temp1 != NULL)
	{
		if (strcmp(temp1->word, str) == 0)
		{
			temp1->count++;
			free(novi->word);
			free(novi);
			return;
		}
		else if (strcmp(temp1->word, str) > 0)
		{
			novi->next = temp1;
			temp->next = novi;
			return;
		}
		temp1 = temp1->next;
		temp = temp->next;
	}

	temp->next = novi;
	novi->next = NULL;
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
	while (dict != NULL)
	{
		Dictionary tmp = dict;
		dict = dict->next;
		free(tmp);
	}
}
