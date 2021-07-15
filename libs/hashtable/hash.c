#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"

void insert_hash(const char *s, Word **hashtable, unsigned long SIZE) {
    unsigned int posicao = string_hash(s, SIZE);
    unsigned int inicial = posicao;


    while (hashtable[posicao] != NULL) {
        if (strcmp(hashtable[posicao]->palavra, s) == 0) {
            hashtable[posicao]->count += 1;
            return;
        }
        posicao++;
        if (posicao > SIZE) posicao = 0;
        if (posicao == inicial) return;
    }

    char *string = (char *) malloc(strlen(s) + 1);
    strcpy(string, s);
    Word *element = (Word *) malloc(sizeof(Word));
    element->palavra = string;
    element->count = 1;
    hashtable[posicao] = element;

}

void find_hash(const char *s, Word **hashtable, unsigned long SIZE) {
    unsigned int posicao = string_hash(s, SIZE);
    unsigned int initial = posicao;
    while (hashtable[posicao] != NULL && strcmp(s, hashtable[posicao]->palavra) != 0) {
        posicao++;
        if (posicao > SIZE) posicao = 0;
        if (posicao == initial || hashtable[posicao] == NULL) {
            printf("O termo não foi encontrado. \n");
        };
    }

    printf("A palavra \"%s\" foi encontrada %lu vezes no arquivo.\n", hashtable[posicao]->palavra,
           hashtable[posicao]->count);
}

void libera_hash(Word **hashtable, unsigned long SIZE) {
    for (int i = 0; i < SIZE; ++i) {
        if (hashtable[i] != NULL) {
            free(hashtable[i]);
        }
    }
    free(hashtable);
}