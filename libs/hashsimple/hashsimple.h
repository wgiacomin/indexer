#ifndef INDEXER_HASHSIMPLE_H
#define INDEXER_HASHSIMPLE_H

#include "../word_struct.h"

void insert_hashsimple(const char *s, Word **hashtable, unsigned long SIZE);

void calc_tfidf(File_Elements **elements, unsigned long SIZE, int number_of_files);

Word **create_table(int n, const char *s);

#endif
