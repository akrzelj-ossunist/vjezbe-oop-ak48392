#ifndef DICTIONARY_H
#define DICTIONARY_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

typedef struct Word {
	int len;
	char* word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word* next;
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnik
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
Dictionary add(Dictionary dict, char* str);

//Funkcija prima rječnik (lista ispunjena sa abecedno poredanim riječima i brojem pojavljivanja u tekstu) i pokazivač na funkciju
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w));

//sortira rječnik od veće do manje riječi
Dictionary sort_long(Dictionary dict);

//sortira rječnik od najviše ponavljanje do najmanje
Dictionary sort_count(Dictionary dict);


//Funkcija filterDictionary() vraća izmijenjenu indict listu koja sadrži samo riječi za koje je filter() 
//funkcija vratila 1 (sve druge riječi se oslobađaju). Funkcija filter() vraća 1 ako je broj pojavljivanja
//riječi između 5 i 10 i ako je riječ duža od 3 znaka.
int filter(Word* w);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// briše cijeli rjeènik
void destroy(Dictionary dict);

//vraća najveću riječ u rječniku
char* long_word(Dictionary dict);

//vraća broj riječi u rječniku
int word_count(Dictionary dict);

//dodaje na pocetak stringa
Dictionary dodaj_u_glavu(Dictionary dict, char* str);

//dodaje na kraj stringa
Dictionary dodaj_na_kraj(Dictionary dict,char* str);

//dodaje negdi u listu
Dictionary dodaj_u_listu(Dictionary dict, char* str,int place);

//uklanja prvi element u listi
Dictionary ukloni_glavu(Dictionary dict);

//uklanja element s kraj
Dictionary ukloni_kraj(Dictionary dict);

//ukloni određenu riječ
Dictionary ukloni_rijec(Dictionary dict,char* str);

//preokrece listu
Dictionary reverse(Dictionary dict);

//preokrece postojecu listu bez da se kreira druga
Dictionary reverse2(Dictionary dict);

//Uklanja vise elemenata iz liste npr. zadnjih 10 elemenata
Dictionary ukloni_elemente(Dictionary dict, int num, int place);

//Dodaje vise elemenata u listu
Dictionary dodaj_elemente(Dictionary dict, int num, int place);

//Prebaci element iz liste iz jednog indeksa u drugi
Dictionary prebaci_element(Dictionary dict, int index_s, int index_e);

//Dodaje/kopira rijeci duze od 10 u novu listu
Dictionary duze_od_10(Dictionary dict, Dictionary dict2);

//Prebacuje rijeci ize jedne liste u drugu sve koje su vece od 10
Dictionary preb_duze_od_10(Dictionary dict, Dictionary *dict2);

#endif

