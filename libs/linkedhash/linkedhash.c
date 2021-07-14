#include "linkedhash.h"
#include "../word_struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void order(Linked_Word *element) {
    if (element->ante == NULL) {
        return;
    }

    while (element->ante->count < element->count) {
        element->ante->prox = element->prox;
        element->prox = element->ante;
        element->ante = element->prox->ante;
        element->prox->ante = element;
        if (element->ante == NULL) {
            return;
        }
    }
}

void insert_linkedhash(const char *s, Descritor *descritor) {
    unsigned int posicao = string_hash(s);
    unsigned int inicial = posicao;

    if (descritor->inicio == NULL) {
        char *string = (char *) malloc(strlen(s) + 1);
        strcpy(string, s);
        Linked_Word *element = (Linked_Word *) malloc(sizeof(Linked_Word));
        element->palavra = string;
        element->count = 1;
        element->prox = NULL;
        element->ante = NULL;
        descritor->inicio = element;
        descritor->final = element;
        descritor->hashtable[posicao] = element;
        return;
    }

    while (descritor->hashtable[posicao] != NULL) {
        if (strcmp(descritor->hashtable[posicao]->palavra, s) == 0) {
            descritor->hashtable[posicao]->count += 1;
            order(descritor->hashtable[posicao]);
            return;
        }
        posicao++;
        if (posicao > SIZE) posicao = 0;
        if (posicao == inicial) return;
    }

    char *string = (char *) malloc(strlen(s) + 1);
    strcpy(string, s);
    Linked_Word *element = (Linked_Word *) malloc(sizeof(Linked_Word));
    element->palavra = string;
    element->count = 1;
    element->prox = NULL;
    element->ante = descritor->final;
    element->ante->prox = element;
    descritor->final = element;
    descritor->hashtable[posicao] = element;
}

unsigned int find_linkedhash(const char *s, Descritor *descritor) {
    unsigned int posicao = string_hash(s);
    unsigned int initial = posicao;
    while (descritor->hashtable[posicao] != NULL && strcmp(s, descritor->hashtable[posicao]->palavra) != 0) {
        posicao++;
        if (posicao > SIZE) posicao = 0;
        if (posicao == initial) return -1;
        if (descritor->hashtable[posicao] == NULL) return -1;
    }
    return posicao;
}

void print_linked(Descritor *descritor, int n) {
    Linked_Word *element = descritor->inicio;
    for (int i = 0; i < n; ++i) {
        printf("%s -> %lu \n", element->palavra, element->count);
        element = element->prox;
    }

    printf("\n\n");
}