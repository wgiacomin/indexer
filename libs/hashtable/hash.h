#ifndef INDEXER_HASH_H
#define INDEXER_HASH_H

#include "../word_struct.h"

void insert_hash(const char *s, Word **hashtable);

unsigned int find_hash(const char *s, Word **hashtable);

void print(Word **hashtable);

#endif
