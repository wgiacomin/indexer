#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "libs/hash_table/hash_table.h"
#include "libs/hash_with_linked_list/hash_with_linked_list.h"
#include "libs/read_files/read_files.h"
#include "libs/simple_array/simple_array.h"


int main(int argc, char **argv) {
    if (argc < 3) {
        return 0;
    }

    if (strcmp(argv[1], "--freq") == 0) {
        unsigned long SIZE = 5000011;
        void **hashtable = (void **) malloc(sizeof(void *) * SIZE);
        Descritor *descritor = (Descritor *) malloc(sizeof(Descritor));
        descritor->inicio = NULL;
        descritor->final = NULL;
        descritor->hashtable = (Linked_Word **) hashtable;
        int n = strtol(argv[2], NULL, 10);
        read_file(argv[3], (void (*)(const char *, void **, unsigned long)) insert_linked_hash, (void **) descritor,
                  SIZE);
        print_hashlinked(descritor, n);
        libera_hashlinked(descritor);

    } else if (strcmp(argv[1], "--freq-word") == 0) {
        unsigned long SIZE = 5000011;
        void **hashtable = (void **) malloc(sizeof(void *) * SIZE);
        read_file(argv[3], (void (*)(const char *, void **, unsigned long)) insert_hash, hashtable, SIZE);
        find_hash(argv[2], (Word **) hashtable, SIZE);
        libera_hash((Word **) hashtable, SIZE);

    } else if (strcmp(argv[1], "--search") == 0) {
        int file_number = (argc - 3);
        unsigned long total_number_of_words;
        int number_of_terms;
        File_Elements **files_table = (File_Elements **) malloc(sizeof(File_Elements *) * file_number);
        number_of_terms = count_words(argv[2]);

        for (int i = 3; i < argc; ++i) {
            File_Elements *file_entry = (File_Elements *) malloc(sizeof(File_Elements));
            Word **word_table = create_table(number_of_terms, argv[2]);

            total_number_of_words = read_file(argv[i],
                                              (void (*)(const char *, void **, unsigned long)) insert_hashsimple,
                                              (void **) word_table, number_of_terms);

            file_entry->n = total_number_of_words;
            file_entry->word_table = word_table;
            file_entry->file_name = argv[i];
            files_table[i - 3] = file_entry;
        }
        calc_tfidf(files_table, number_of_terms, file_number);
        print_hashsimple(files_table, file_number, argv[2]);
        libera_simples(files_table, file_number, number_of_terms);

    } else {
        printf("Comando não encontrado.");
    }
}
