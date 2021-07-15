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

int count_words(const char *s) {
    int j = 1;
    int k;

    for (k = 0; s[k] != '\0'; ++k) {
        if (s[k] == ' ') {
            j++;
        }
    }

    return j;
}