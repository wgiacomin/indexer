#include <string.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include "hashsimple.h"

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

void calc_tfidf(File_Elements **elements, unsigned long SIZE, int number_of_files) {
    double tfidf;
    double tf;
    int count = 0;

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

    for (int j = 0; j < number_of_files; ++j) {
        printf("%f %s \n", elements[j]->tfidf, elements[j]->file_name);
    }
}

