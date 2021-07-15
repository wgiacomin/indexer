#ifndef INDEXER_WORD_STRUCT_H
#define INDEXER_WORD_STRUCT_H

typedef struct word_count {
    char *palavra;
    double tf;
    double tfidf;
    unsigned long count;
} Word;

typedef struct linked_word_count {
    char *palavra;
    unsigned long count;
    struct linked_word_count *ante;
    struct linked_word_count *prox;
} Linked_Word;

typedef struct descritor {
    Linked_Word *inicio;
    Linked_Word *final;
    Linked_Word **hashtable;
} Descritor;

typedef struct word_number {
    Word **word_table;
    unsigned long n;
} Word_Elements;

typedef struct file_table {
    Word_Elements *table;
    double tfidf;
    char *file_name;
} File_Elements;

unsigned int string_hash(const char *s, unsigned long SIZE);

#endif
