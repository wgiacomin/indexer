#include <stdio.h>
#include <string.h>
#include "libs/hashtable/hashtable.h"
#include "libs/read_files/read_files.h"

int main(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        printf("%s ", argv[i]);
    }

    read_files("D:\\Codigos\\Estruturas de Dados 2\\indexer\\assets\\small\\101.txt", insert_hash);
    print();
}
