#include <stdio.h>
#include <malloc.h>
#include "libs/hashtable/hash.h"
#include "libs/linkedhash/linkedhash.h"
#include "libs/read_files/read_files.h"

void *hashtable[SIZE];

int main(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        printf("%s ", argv[i]);
    }

//    read_files("D:\\Codigos\\Estruturas de Dados 2\\indexer\\assets\\small\\101.txt",
//               (void (*)(const char *, void **)) insert_hash, hashtable);
//    print((Word **) hashtable);
    Descritor *descritor = (Descritor *) malloc(sizeof(Descritor));
    descritor->inicio = NULL;
    descritor->final = NULL;
    descritor->hashtable = (Linked_Word **) hashtable;

    read_files("D:\\Codigos\\Estruturas de Dados 2\\indexer\\assets\\small\\101.txt",
               (void (*)(const char *, void **)) insert_linkedhash, (void **) descritor);
    print_linked(descritor, 4);
}
