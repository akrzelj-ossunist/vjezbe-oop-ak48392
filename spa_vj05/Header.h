#ifndef DICTIONARY_H
#define DICTIONARY_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

typedef struct Word {
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

Dictionary cnt(Dictionary dict);

//Funkcija filterDictionary() vraća izmijenjenu indict listu koja sadrži samo riječi za koje je filter() 
//funkcija vratila 1 (sve druge riječi se oslobađaju). Funkcija filter() vraća 1 ako je broj pojavljivanja
//riječi između 5 i 10 i ako je riječ duža od 3 znaka.
int filter(Word* w);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// briše cijeli rjeènik
void destroy(Dictionary dict);

#endif
