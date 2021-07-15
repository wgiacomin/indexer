#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "libs/hashtable/hash.h"
#include "libs/linkedhash/linkedhash.h"
#include "libs/read_files/read_files.h"


int main(int argc, char **argv) {
    if (argc < 3) {
        return 0;
    }

    if (strcmp(argv[1], "--freq") == 0) {
        void **hashtable = (void **) malloc(sizeof(void *) * SIZE);
        Descritor *descritor = (Descritor *) malloc(sizeof(Descritor));
        descritor->inicio = NULL;
        descritor->final = NULL;
        descritor->hashtable = (Linked_Word **) hashtable;
        int n = strtol(argv[2], NULL, 10);
        read_file(argv[3], (void (*)(const char *, void **)) insert_linkedhash, (void **) descritor);
        print_linked(descritor, n);
        libera_linkedhash(descritor);

    } else if (strcmp(argv[1], "--freq-word") == 0) {
        void **hashtable = (void **) malloc(sizeof(void *) * SIZE);
        read_file(argv[3], (void (*)(const char *, void **)) insert_hash, hashtable);
        find_hash(argv[2], (Word **) hashtable);
        libera_hash((Word **) hashtable);

    } else if (strcmp(argv[1], "--search") == 0) {
        int relevant_file_number = (argc - 3) / 2 + 1;
        int number_of_words = count_words(argv[2]);
        void **files_table = (void **) malloc(sizeof(void *) * relevant_file_number);
        void **word_table = (void **) malloc(sizeof(void *) * number_of_words);
        for (int i = 3; i < argc; ++i) {

        }

    } else {
        printf("Comando não encontrado.");
    }


}
