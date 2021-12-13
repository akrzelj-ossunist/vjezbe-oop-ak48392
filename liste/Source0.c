#include "Header.h"



int readWord(FILE* fd, char* buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	FILE* fd;
	char buffer[1024];
	Dictionary dict;

	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	dict = create();
	while (readWord(fd, buffer))
		dict = add(dict, buffer);
		
	//dict = filterDictionary(dict, filter);

	char* l_word = long_word(dict);
	puts("Longest word is: ");
	puts(l_word);
	puts(" ");

	int count = word_count(dict);

	printf("There are %d words in dictionary. \n", count);
	puts(" ");

	

	dict = sort_count(dict);

	dict = sort_long(dict);
	fclose(fd);

	//char str[] = "Banana";

	//dict = dodaj_u_glavu(dict, str);

	//dict = dodaj_na_kraj(dict, str);

	//dict = dodaj_u_listu(dict, str, count - 2);

	//dict = ukloni_glavu(dict);

	//dict = ukloni_kraj(dict);

	//dict = ukloni_rijec(dict, str);

	//dict = reverse(dict);

	//dict = reverse2(dict);

	//int num, place;
	//printf("Koliko zelite elemenata ukloniti i gdje: ");
	//scanf("%d %d", &num, &place);
	//dict = ukloni_elemente(dict, num, place);

	//printf("Koliko zelite dodati elemenata i gdje: ");
	//scanf("%d %d", &num, &place);
	//dict = dodaj_elemente(dict, num, place);
	//puts(" ");

	//int index_s = 1, index_e = 20;
	//dict = prebaci_element(dict, index_s, index_e);

	//Dictionary dict2 = create();
	//dict2 = duze_od_10(dict, dict2);
	//dict = preb_duze_od_10(dict, &dict2);

	//print(dict);

	//print(dict2);
	destroy(dict);
}