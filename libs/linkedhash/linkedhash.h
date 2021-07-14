#ifndef INDEXER_LINKEDHASH_H
#define INDEXER_LINKEDHASH_H

#include "../word_struct.h"

void insert_linkedhash(const char *s, Descritor *descritor);

unsigned int find_linkedhash(const char *s, Descritor *descritor);

void print_linked(Descritor *descritor, int n);

#endif
