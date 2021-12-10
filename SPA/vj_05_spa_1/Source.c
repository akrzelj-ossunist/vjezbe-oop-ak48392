#include "Header.h"


Dictionary create()
{
	Dictionary dict = (Dictionary)malloc(sizeof(Word));
	dict = NULL;
	return dict;
}

Dictionary add(Dictionary dict, char* str)
{
	Dictionary tmp = dict;
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(novi->word, str);
	novi->count = 1;
	novi->next = NULL;
	if (dict == NULL)
	{
		tmp = novi;
		return tmp;
	}
	if (tmp->next == NULL)
	{
		if (strcmp(tmp->word, str) > 0)
		{
			novi->next = tmp;
			return novi;
		}
	}
	if (strcmp(tmp->word, str) == 0)
	{
		tmp->count += 1;
		return dict;
	}
	if (strcmp(tmp->word, str) > 0)
	{
		novi->next = tmp;
		return novi;
	}
	while (tmp->next != NULL)
	{
		if (strcmp(tmp->next->word, str) == 0)
		{
			tmp->next->count += 1;
			return dict;
		}
		if (strcmp(tmp->next->word, str) > 0)
		{
			novi->next = tmp->next;
			tmp->next = novi;
			return dict;
		}
		tmp = tmp->next;
	}
	tmp->next = novi;
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

	while (temp->next != NULL)
	{
		int Bool = filter(temp->next);
		if (Bool == 0)
			temp->next = temp->next->next;
		else
			temp = temp->next;
	}
	int Bool = filter(indict);
	if (Bool == 0)
		indict = indict->next;
	return indict;
}

void print(Dictionary dict)
{
	while (dict != NULL)
	{
		printf("%s %d\n", dict->word, dict->count);
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
