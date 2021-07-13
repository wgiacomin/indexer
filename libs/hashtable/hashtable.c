#include "hashtable.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

unsigned int string_hash(const char* s)
{
    unsigned int hash = 5381;
    while (*s)
        hash = 33 * hash ^ (unsigned char) *s++;
    return hash % SIZE;
}

void insert_hash(char *s) {
    unsigned int posicao = string_hash(s);
    unsigned int inicial = posicao;

    while (hashtable[posicao] != NULL) {
        if (strcmp(hashtable[posicao]->palavra, s) == 0){
            hashtable[posicao]->count += 1;
            return;
        }
        posicao++;
        if (posicao > SIZE) posicao = 0;
        if (posicao == inicial) return;
    }

    char *string = (char *) malloc(strlen(s));
    strcpy(string, s);
    Word *element = (Word *) malloc(sizeof (Word));
    element->palavra = string;
    element->count = 1;
    hashtable[posicao] = element;

}

unsigned int find_hash(const char *s) {
    unsigned int posicao = string_hash(s);
    unsigned int initial = posicao;
    while (hashtable[posicao] != NULL && strcmp(s, hashtable[posicao]->palavra) != 0) {
        posicao++;
        if (posicao > SIZE) posicao = 0;
        if (posicao == initial) return -1;
        if (hashtable[posicao] == NULL) return -1;
    }
    return posicao;
}

void print() {
    for (int i = 0; i < SIZE; ++i) {
        if (hashtable[i] != NULL) {
            printf("%s -> %lu \n", hashtable[i]->palavra, hashtable[i]->count);
        }
    }
    printf("\n\n");
}