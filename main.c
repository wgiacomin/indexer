#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "libs/hashtable/hash.h"
#include "libs/hashlinked/hashlinked.h"
#include "libs/read_files/read_files.h"
#include "libs/hashsimple/hashsimple.h"


int main(int argc, char **argv) {
    if (argc < 3) {
        return 0;
    }

    if (strcmp(argv[1], "--freq") == 0) {
        unsigned long SIZE = 499883;
        void **hashtable = (void **) malloc(sizeof(void *) * SIZE);
        Descritor *descritor = (Descritor *) malloc(sizeof(Descritor));
        descritor->inicio = NULL;
        descritor->final = NULL;
        descritor->hashtable = (Linked_Word **) hashtable;
        int n = strtol(argv[2], NULL, 10);
        read_file(argv[3], (void (*)(const char *, void **, unsigned long)) insert_hashlinked, (void **) descritor,
                  SIZE);
        print_hashlinked(descritor, n);
        libera_hashlinked(descritor);

    } else if (strcmp(argv[1], "--freq-word") == 0) {
        unsigned long SIZE = 499883;
        void **hashtable = (void **) malloc(sizeof(void *) * SIZE);
        read_file(argv[3], (void (*)(const char *, void **, unsigned long)) insert_hash, hashtable, SIZE);
        find_hash(argv[2], (Word **) hashtable, SIZE);
        libera_hash((Word **) hashtable, SIZE);

    } else if (strcmp(argv[1], "--search") == 0) {
        int file_number = (argc - 3);
        unsigned long total_number_of_words;
        int number_of_terms;
        File_Elements **files_table = (File_Elements **) malloc(sizeof(File_Elements *) * file_number);

        for (int i = 3; i < argc; ++i) {
            Word_Elements *word_elements = count_words(argv[2]);
            number_of_terms = (int) word_elements->n;
            total_number_of_words = read_file(argv[3],
                                              (void (*)(const char *, void **, unsigned long)) insert_hashsimple,
                                              (void **) word_elements->word_table, word_elements->n);
            word_elements->n = total_number_of_words;

            File_Elements *file_entry = (File_Elements *) malloc(sizeof(File_Elements));
            file_entry->table = word_elements;
            file_entry->file_name = argv[3];
            files_table[i - 3] = file_entry;
        }
        calc_tfidf(files_table, number_of_terms, file_number);
    } else {
        printf("Comando não encontrado.");
    }


}
