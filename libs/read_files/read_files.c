#include "read_files.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void read_files(char *filename, void (*inserir)(const char *, Word **), Word **hashtable) {
    FILE *fp;
    int letra, i;
    char palavra[255];

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Erro ao abrir o arquivo %s.", filename);
        return;
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
            inserir(palavra, hashtable);
        }
    }

    fclose(fp);

}