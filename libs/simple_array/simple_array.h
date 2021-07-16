#ifndef INDEXER_SIMPLE_ARRAY_H
#define INDEXER_SIMPLE_ARRAY_H

#include "../word_struct.h"

void insert_hashsimple(const char *s, Word **hashtable, unsigned long SIZE);

void calc_tfidf(File_Elements **elements, unsigned long SIZE, int number_of_files);

Word **create_table(int n, const char *s);

void print_hashsimple(File_Elements **elements, int number_of_files, char *s);

void libera_simples(File_Elements **elements, int file_number, int word_number);

#endif
