#ifndef INDEXER_HASHTABLE_H
#define INDEXER_HASHTABLE_H
#include "../word_struct.h"
#define SIZE 499883
Word *hashtable[SIZE];

unsigned int string_hash(const char* s);
void insert_hash(char *s);
unsigned int find_hash(const char *s);
void print();

#endif
