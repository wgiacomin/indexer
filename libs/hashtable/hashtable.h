#ifndef INDEXER_HASHTABLE_H
#define INDEXER_HASHTABLE_H
#include "../word_struct.h"

#define SIZE 499883


unsigned int string_hash(const char* s);
void insert_hash(const char *s, Word **hashtable);
unsigned int find_hash(const char *s, Word **hashtable);
void print(Word **hashtable);

#endif
