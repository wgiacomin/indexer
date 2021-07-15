#ifndef INDEXER_READ_FILES_H
#define INDEXER_READ_FILES_H

#include "../word_struct.h"

unsigned long
read_file(char *filename, void (*inserir)(const char *, void **, unsigned long), void **hashtable, unsigned long SIZE);

Word_Elements *count_words(const char *s);

#endif
