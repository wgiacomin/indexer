all: indexer

indexer: main.o word_struct.o read_files.o hash_table.o simple_array.o hash_with_linked_list.o
	gcc -o indexer main.o word_struct.o read_files.o hash_table.o simple_array.o hash_with_linked_list.o -std=c11

main.o: main.c ./libs/word_struct.h ./libs/read_files/read_files.h ./libs/hash_table/hash_table.h ./libs/simple_array/simple_array.h ./libs/hash_with_linked_list/hash_with_linked_list.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic -std=c11

word_struct.o: ./libs/word_struct.c ./libs/word_struct.h
	gcc -o word_struct.o ./libs/word_struct.c -c -W -Wall -ansi -pedantic -std=c11

read_files.o: ./libs/read_files/read_files.c ./libs/read_files/read_files.h word_struct.o
	gcc -o read_files.o ./libs/read_files/read_files.c -c -W -Wall -ansi -pedantic -std=c11

hash_table.o: ./libs/hash_table/hash_table.c ./libs/hash_table/hash_table.h word_struct.o
	gcc -o hash_table.o ./libs/hash_table/hash_table.c -c -W -Wall -ansi -pedantic -std=c11

simple_array.o: ./libs/simple_array/simple_array.c ./libs/simple_array/simple_array.h word_struct.o
	gcc -o simple_array.o ./libs/simple_array/simple_array.c -c -W -Wall -ansi -pedantic -std=c11

hash_with_linked_list.o: ./libs/hash_with_linked_list/hash_with_linked_list.c ./libs/hash_with_linked_list/hash_with_linked_list.h word_struct.o
	gcc -o hash_with_linked_list.o ./libs/hash_with_linked_list/hash_with_linked_list.c -c -W -Wall -ansi -pedantic -std=c11

clean:
	rm -rf *.o



