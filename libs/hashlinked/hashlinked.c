#include "hashlinked.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void order(Linked_Word *element) {
    if (element->ante == NULL) {
        return;
    }

    Linked_Word *aux;
    while (element->ante->count < element->count) {
        aux = element->ante;
        aux->prox = element->prox;
        element->ante = aux->ante;
        aux->ante = element;
        element->prox = aux;
        if (aux->prox != NULL) {
            aux->prox->ante = aux;
        }
        if (element->ante == NULL) {
            return;
        }
        element->ante->prox = element;
    }
}

void insert_hashlinked(const char *s, Descritor *descritor, unsigned long SIZE) {
    unsigned int posicao = string_hash(s, SIZE);
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
            descritor->hashtable[posicao]->count++;
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
    descritor->final->prox = element;
    descritor->final = element;
    descritor->hashtable[posicao] = element;
}

void print_hashlinked(Descritor *descritor, int n) {
    Linked_Word *element = descritor->inicio;
    printf("As %d palavras que mais se repetiram foram: \n\n", n);
    printf("    n |     vezes | palavra \n");
    for (int i = 0; i < n; ++i) {
        if (element->count < 999999999) {
            printf("%5d | %9lu | %s\n", i + 1, element->count, element->palavra);
            element = element->prox;
        } else {
            printf("%5d | %lu | %s\n", i + 1, element->count, element->palavra);
        }
    }

    printf("\n\n");
}

void libera_hashlinked(Descritor *descritor) {
    Linked_Word *aux, *element = descritor->inicio;
    int i = 0;
    while (element->prox != NULL) {
        i++;
        aux = element;
        element = element->prox;
        free(aux);
    }
    free(element);
    free(descritor->hashtable);
    free(descritor);
}