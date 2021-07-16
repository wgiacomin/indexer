#ifndef INDEXER_HASH_TABLE_H
#define INDEXER_HASH_TABLE_H

#include "../word_struct.h"

void insert_hash(const char *s, Word **hashtable, unsigned long SIZE);

void find_hash(const char *s, Word **hashtable, unsigned long SIZE);

void libera_hash(Word **hashtable, unsigned long SIZE);

#endif
