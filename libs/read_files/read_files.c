#include "read_files.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

unsigned long
read_file(char *filename, void (*inserir)(const char *, void **, unsigned long), void **hashtable, unsigned long SIZE) {
    FILE *fp;
    int letra, i;
    char palavra[255];
    unsigned long count = 0;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Erro ao abrir o arquivo \"%s\".", filename);
        return 0;
    }

    while (!feof(fp)) {
        letra = getc(fp);
        i = 0;
        while ((letra > 64 && letra < 91) || (letra > 96 && letra < 123)) {
            if (letra > 64 && letra < 91) {
                letra += 32;
            }

            if (letra > 96 && letra < 123) {
                palavra[i] = (char) letra;
            }
            i++;
            letra = getc(fp);
        }

        if (i > 0) {
            palavra[i] = '\000';
            inserir(palavra, hashtable, SIZE);
            count++;
        }
    }
    fclose(fp);
    return count;
}

Word_Elements *count_words(const char *s) {
    int j = 1;
    int k, l;
    Word_Elements *results = (Word_Elements *) malloc((sizeof(Word_Elements)));
    for (k = 0; s[k] != '\0'; ++k) {
        if (s[k] == ' ') {
            j++;
        }
    }
    results->n = j;
    l = 0;
    Word **word_table = (Word **) malloc(sizeof(Word *) * j);
    char palavra[50];
    j = 0;
    for (int i = 0; i < k + 1; ++i) {
        if (s[i] == ' ' || s[i] == '\0') {
            if (j > 0) {
                palavra[i] = '\000';
                Word *element = (Word *) malloc(sizeof(Word));
                char *string = (char *) malloc(strlen(s) + 1);
                strcpy(string, palavra);
                element->palavra = string;
                element->count = 0;
                word_table[l] = element;
                l++;
            }
            j = 0;

        } else if ((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123)) {
            if (s[i] > 64 && s[i] < 91) {
                palavra[j] = (char) ((int) s[i] + 32);
            } else {
                palavra[j] = s[i];
            }
            j++;
        }
    }
    results->word_table = word_table;
    return results;
}