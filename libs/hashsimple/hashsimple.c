#include <string.h>
#include <math.h>
#include <stdio.h>
#include "hashsimple.h"

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
        for (int j = 0; j < number_of_files; ++j) {
            tf = (double) elements[j]->table->word_table[i]->count / elements[j]->table->n;
            if (tf > 0) {
                count++;
            }
            elements[j]->table->word_table[i]->tf = tf;
        }
        for (int j = 0; j < number_of_files; ++j) {
            elements[j]->table->word_table[i]->tfidf =
                    elements[j]->table->word_table[i]->tf * log((double) number_of_files / count);
        }
    }

    for (int j = 0; j < number_of_files; ++j) {
        tfidf = 0;
        for (int i = 0; i < SIZE; ++i) {
            tfidf += elements[j]->table->word_table[i]->tfidf;
        }
        tfidf = tfidf / SIZE;
        elements[j]->tfidf = tfidf;
    }

    for (int j = 0; j < number_of_files; ++j) {
        printf("%f %s \n", elements[j]->tfidf, elements[j]->file_name);
    }

}

