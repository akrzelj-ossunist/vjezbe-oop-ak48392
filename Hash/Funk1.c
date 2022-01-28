#include "header.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define HCONST 3567892

HashTable* NewTable(int size)
{
    HashTable* Table = (HashTable*)malloc(sizeof(HashTable));
    if (Table == NULL) return 0;
    Table->table = (Bin**)malloc(size * sizeof(Bin));
    if (Table->table == NULL) return 0;

    Table->size = size;
    Table->load = 0;

    for (int i = 0; i <= size; i++)
        Table->table[i] = NULL;

    return Table;
}

unsigned int hash(char* word)
{
    // od kljuca generira hash kod
    unsigned int key = 0;
    while (*word != '\0')
    {
        key = key * HCONST + *word;
        word++;
    }
    return key;
}


void Insert(HashTable* ht, char* word)
{
    // dodaje novu rijec u listu na odgovarajucem pretincu
    int key = hash(word) % ht->size;

    if (ht->table[key] == NULL) {
        Bin* newSlot = (Bin*)malloc(sizeof(Bin));
        newSlot->word = _strdup(word);
        newSlot->next = NULL;
        ht->table[key] = newSlot;
    }  
    else
    {
        Bin* lastWord = ht->table[key];
        Bin* newSlot = (Bin*)malloc(sizeof(Bin));
        newSlot->word = _strdup(word);
        newSlot->next = lastWord; 
    }
    (ht->load)++;
}

int Get(HashTable* ht, char* word)
{
    int key = hash(word) % ht->size;

    return (ht->table[key] == NULL) ? 0 : 1;
}

void DeleteTable(HashTable* ht)
{
    for (int i = 0; i < ht->size; i++)
        if (ht->table[i] != NULL)
            while (ht->table[i]) {
                Bin* newTable = ht->table[i];
                ht->table[i] = ht->table[i]->next;
                free(newTable);
            }
    free(ht->table);
}



