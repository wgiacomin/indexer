#ifndef INDEXER_READ_FILES_H
#define INDEXER_READ_FILES_H

#include "../word_struct.h"

void
read_file(char *filename, void (*inserir)(const char *, void **, unsigned long), void **hashtable, unsigned long SIZE);

int count_words(const char *s);

#endif
