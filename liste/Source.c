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
	novi->len = (int)malloc(sizeof(int));
	novi->len = strlen(str);
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
		printf("Broj ponavljanja: %d\t Rijec: %s\t\t Duzina rijeci: %d \n", dict->count, dict->word,dict->len);
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

char* long_word(Dictionary dict)
{
	char* l_word = (char*)malloc(sizeof(char) * 20);
	strcpy(l_word, dict->word);
	while (dict != NULL)
	{
		if (strlen(l_word) < strlen(dict->word))
			strcpy(l_word, dict->word);
		dict = dict->next;
	}
	return l_word;
}

Dictionary sort_long(Dictionary dict)
{

	char* s_word = (char*)malloc(sizeof(char) * 20);
	Dictionary tmp = dict;
	Dictionary tmp1 = dict;
	while (tmp != NULL)
	{
		while (tmp1 != NULL)
		{
			if (tmp->len > tmp1->len) {
				int temp = tmp->count;
				tmp->count = tmp1->count;
				tmp1->count = temp;
				strcpy(s_word, tmp->word);
				strcpy(tmp->word, tmp1->word);
				strcpy(tmp1->word, s_word);
				temp = tmp->len;
				tmp->len = tmp1->len;
				tmp1->len = temp;
				break;
			}
			tmp1 = tmp1->next;
		}
		if (tmp1 == NULL)
			tmp = tmp->next;
		tmp1 = dict;
			
	}
	return dict;
}

int word_count(Dictionary dict)
{
	int count = 0;
	while (dict != NULL)
	{
		count += 1;
		dict = dict->next;
	}
	return count;
}

Dictionary sort_count(Dictionary dict)
{

	char* s_word = (char*)malloc(sizeof(char) * 20);
	Dictionary tmp = dict;
	Dictionary tmp1 = dict;
	while (tmp != NULL)
	{
		while (tmp1 != NULL)
		{
			if (tmp->count > tmp1->count) {
				int temp = tmp->count;
				tmp->count = tmp1->count;
				tmp1->count = temp;
				strcpy(s_word, tmp->word);
				strcpy(tmp->word, tmp1->word);
				strcpy(tmp1->word, s_word);
				temp = tmp->len;
				tmp->len = tmp1->len;
				tmp1->len = temp;
				break;
			}
			tmp1 = tmp1->next;
		}
		if (tmp1 == NULL)
			tmp = tmp->next;
		tmp1 = dict;

	}
	return dict;
}

Dictionary dodaj_u_glavu(Dictionary dict, char* str)
{
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
	strcpy(novi->word, str);
	novi->count = 1;
	novi->len = strlen(str);
	novi->next = dict;
	return novi;
}

Dictionary dodaj_na_kraj(Dictionary dict, char* str)
{
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
	strcpy(novi->word, str);
	novi->count = 1;
	novi->len = strlen(str);
	novi->next = NULL;
	Dictionary tmp = dict;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = novi;
	return dict;
}

Dictionary dodaj_u_listu(Dictionary dict, char* str, int place)
{
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
	strcpy(novi->word, str);
	novi->count = 1;
	novi->len = strlen(str);
	Dictionary tmp = dict;
	int br = 1;
	while (tmp->next != NULL)
	{
		if (br == place)
		{
			novi->next = tmp->next;
			tmp->next = novi;
			break;
		}
		br++;
		tmp = tmp->next;
	}
	return dict;
}

Dictionary ukloni_glavu(Dictionary dict)
{
	Dictionary tmp = dict;
	dict = dict->next;
	free(tmp);
	return dict;
}

Dictionary ukloni_kraj(Dictionary dict)
{
	Dictionary tmp = dict;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	return dict;
}

Dictionary ukloni_rijec(Dictionary dict, char* str)
{
	Dictionary tmp = dict;
	while (tmp->next->next != NULL)
	{
		if (strcmp(tmp->next->word, str) == 0) {
			tmp->next = tmp->next->next;
		}
		else
			tmp = tmp->next;
	}
	return dict;
}

Dictionary reverse(Dictionary dict)
{
	Dictionary tmp = NULL;
	while (dict != NULL)
	{
		Dictionary novi = (Dictionary)malloc(sizeof(Word));
		novi->word = (char*)malloc(sizeof(char) * dict->len + 1);
		strcpy(novi->word, dict->word);
		novi->count = dict->count;
		novi->len = dict->len;
		novi->next = tmp;
		tmp = novi;
		dict = dict->next;
	}
	return tmp;
}

Dictionary reverse2(Dictionary dict)
{
	Dictionary tmp = dict;
	Dictionary prethodni = NULL;
	Dictionary sljedeci = NULL;
	while (tmp != NULL)
	{
		sljedeci = tmp->next;
		tmp->next = prethodni;
		prethodni = tmp;
		tmp = sljedeci;
	}
	dict = prethodni;
	return dict;
}

Dictionary ukloni_elemente(Dictionary dict, int num, int place)
{
	int br = 2;
	Dictionary tmp = dict;
	if (place == 1)
	{
		while (tmp != NULL && num != 0)
		{
			tmp = dict;
			dict = dict->next;
			free(tmp);
			num--;
		}
		return dict;
	}
	while (tmp->next != NULL)
	{
		if (br == place)
		{
			while (tmp != NULL && num != 0)
			{
				Dictionary tmp1 = tmp->next;
				tmp->next = tmp->next->next;
				free(tmp1);
				num--;
			}
			break;
		}
		br++;
		tmp = tmp->next;
	}
	return dict;
}

Dictionary dodaj_elemente(Dictionary dict, int num, int place)
{
	int br = 1;
	int len = num;
	char* str = (char*)malloc(sizeof(char) * 20);
	Dictionary tmp = dict;
	while (tmp != NULL)
	{
		if (place == 1)
		{
			while (tmp != NULL && num != 0) {
				printf("Unesite rjec koju zelite dodat: ");
				scanf("%s", str);
				Dictionary novi = (Dictionary)malloc(sizeof(Word));
				novi->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
				strcpy(novi->word, str);
				novi->len = strlen(str);
				novi->count = 1;
				novi->next = tmp;
				tmp = novi;
				num--;
			}
			return tmp;
		}
		if (br == place - 1)
		{
			while (tmp != NULL && num != 0) {
				printf("Unesite rjec koju zelite dodat: ");
				scanf("%s", str);
				Dictionary novi = (Dictionary)malloc(sizeof(Word));
				novi->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
				strcpy(novi->word, str);
				novi->len = strlen(str);
				novi->count = 1;
				novi->next = tmp->next;
				tmp->next = novi;
				num--;
				tmp = tmp->next;
			}
			break;
		}
		if (tmp->next == NULL)
		{
			while (num != 0) {
				printf("Unesite rjec koju zelite dodat: ");
				scanf("%s", str);
				Dictionary novi = (Dictionary)malloc(sizeof(Word));
				novi->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
				strcpy(novi->word, str);
				novi->len = strlen(str);
				novi->count = 1;
				tmp->next = novi;
				num--;
				tmp = tmp->next;
			}
			break;
		}
		tmp = tmp->next;
		br++;
	}
	return dict;
}
Dictionary prebaci_element(Dictionary dict, int index_s, int index_e)
{
	int br = 2;
	Dictionary tmp = dict;
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = (char*)malloc(sizeof(char) * 20);
	if (index_s == 1)
	{
		strcpy(novi->word, tmp->word);
		novi->len = tmp->len;
		novi->count = tmp->count;
		dict = dict->next;
	}
	tmp = dict;
	while (tmp->next != NULL)
	{
		if (index_s == br)
		{
			strcpy(novi->word, tmp->next->word);
			novi->len = tmp->next->len;
			novi->count = tmp->next->count;
			Dictionary tmp1 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp1);
		}
		if (index_e == br)
		{
			Dictionary tmp1 = tmp->next;
			novi->next = tmp1;
			tmp->next = novi;
			break;
		}
		else
			tmp = tmp->next;
		br++;
	}
	return dict;
}

Dictionary duze_od_10(Dictionary dict, Dictionary dict2)
{
	while (dict != NULL)
	{
		if (dict->len > 10)
		{
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			novi->word = (char*)malloc(sizeof(char) * dict->len + 1);
			strcpy(novi->word, dict->word);
			novi->len = dict->len;
			novi->count = dict->count;
			novi->next = dict2;
			dict2 = novi;
		}
		dict = dict->next;
	}
	return dict2;
}

Dictionary preb_duze_od_10(Dictionary dict, Dictionary *dict2)
{
	Dictionary tmp = dict;
	while (tmp->next != NULL)
	{
		if (tmp->next->len > 10)
		{
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			novi->word = (char*)malloc(sizeof(char) * tmp->next->len + 1);
			strcpy(novi->word, tmp->next->word);
			novi->len = tmp->next->len;
			novi->count = tmp->next->count;
			novi->next = *dict2;
			*dict2 = novi;
			Dictionary tmp1 = tmp->next;
			tmp->next = tmp1->next;
			free(tmp1);
		}
		else
			tmp = tmp->next;
	}
	if (dict->len > 10)
	{
		Dictionary novi = (Dictionary)malloc(sizeof(Word));
		novi->word = (char*)malloc(sizeof(char) * tmp->len + 1);
		strcpy(novi->word, tmp->word);
		novi->len = tmp->len;
		novi->count = tmp->count;
		novi->next = *dict2;
		*dict2 = novi;
		dict = dict->next;
	}
	return dict;
}