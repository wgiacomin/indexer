#include <string.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include "simple_array.h"

Word **create_table(int n, const char *s) {
    int l = 0, j;

    Word **word_table = (Word **) malloc(sizeof(Word *) * n);

    char palavra[50];
    j = 0;
    for (int i = 0; l < n; ++i) {
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

    return word_table;
}

void insert_hashsimple(const char *s, Word **hashtable, unsigned long SIZE) {
    for (int i = 0; i < SIZE; ++i) {
        if (strcmp(hashtable[i]->palavra, s) == 0) {
            hashtable[i]->count++;
        }
    }
}

void swap(File_Elements **a, int i, int j) {
    File_Elements *swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

void insertion_sort(File_Elements **a, int r) {
    for (int i = 0; i <= r; i++)
        for (int j = i; j > 0 && a[j]->tfidf > a[j - 1]->tfidf; j--)
            swap(a, j, j - 1);
}

void calc_tfidf(File_Elements **elements, unsigned long SIZE, int number_of_files) {
    double tfidf;
    double tf;
    int count;

    for (int i = 0; i < SIZE; ++i) {
        count = 0;
        for (int j = 0; j < number_of_files; ++j) {
            tf = (double) elements[j]->word_table[i]->count / elements[j]->n;
            if (tf > 0) {
                count++;
            }
            elements[j]->word_table[i]->tf = tf;
        }
        for (int j = 0; j < number_of_files; ++j) {
            if (number_of_files == count || count == 0) {
                elements[j]->word_table[i]->tfidf = 0;
            } else {
                elements[j]->word_table[i]->tfidf =
                        elements[j]->word_table[i]->tf * log((double) number_of_files / count);
            }
        }
    }

    for (int j = 0; j < number_of_files; ++j) {
        tfidf = 0;
        for (int i = 0; i < SIZE; ++i) {
            tfidf += elements[j]->word_table[i]->tfidf;
        }
        tfidf = tfidf / SIZE;
        elements[j]->tfidf = tfidf;
    }

}

void print_hashsimple(File_Elements **elements, int number_of_files, char *s) {
    int count = 0;
    insertion_sort(elements, number_of_files - 1);
    printf("A lista dos %d arquivos mais relevantes para o termo \"%s\":\n\n", number_of_files / 2 + 1, s);
    printf("   TFIDF | Diretorio \n");
    for (int j = 0; j < number_of_files / 2 + 1; ++j) {
        if (elements[j]->tfidf > 0) {
            printf("%.6f | %s \n", elements[j]->tfidf, elements[j]->file_name);
            count++;
        }
    }
    if (count == 0) {
        printf("     -   |     -      \n");
    }
}

void libera_simples(File_Elements **elements, int file_number, int word_number) {
    for (int j = 0; j < file_number; ++j) {
        for (int k = 0; k < word_number; ++k) {
            free(elements[j]->word_table[k]->palavra);
            free(elements[j]->word_table[k]);
        }
        free(elements[j]);
    }
    free(elements);
}
