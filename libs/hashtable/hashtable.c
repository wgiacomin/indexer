
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashtable.h"


unsigned int string_hash(const char* s)
{
    unsigned int hashtable = 5381;
    while (*s)
        hashtable = 33 * hashtable ^ (unsigned char) *s++;
    return hashtable % SIZE;
}

void insert_hash(const char *s, Word **hashtable) {
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

    char *string = (char *) malloc(strlen(s) + 1);
    strcpy(string, s);
    Word *element = (Word *) malloc(sizeof (Word));
    element->palavra = string;
    element->count = 1;
    hashtable[posicao] = element;

}

unsigned int find_hash(const char *s, Word **hashtable) {
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

void print(Word **hashtable) {
    for (int i = 0; i < SIZE; ++i) {
        if (hashtable[i] != NULL) {
            printf("%s -> %lu \n", hashtable[i]->palavra, hashtable[i]->count);
        }
    }
    printf("\n\n");
}