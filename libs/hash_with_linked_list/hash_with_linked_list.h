#ifndef INDEXER_HASH_WITH_LINKED_LIST_H
#define INDEXER_HASH_WITH_LINKED_LIST_H

#include "../word_struct.h"

void insert_hashlinked(const char *s, Descritor *descritor, unsigned long SIZE);

void print_hashlinked(Descritor *descritor, int n);

void libera_hashlinked(Descritor *descritor);

#endif
