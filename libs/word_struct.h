#ifndef INDEXER_WORD_STRUCT_H
#define INDEXER_WORD_STRUCT_H
#define SIZE 499883


typedef struct word_count {
    char *palavra;
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

typedef struct file_tfidf {
    char *file;
    double tfidf;
} Entry_TFIDF;

unsigned int string_hash(const char *s);

#endif
