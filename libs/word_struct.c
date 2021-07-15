#include "word_struct.h"

unsigned long string_hash(const char *s, unsigned long SIZE) {
    unsigned long hash = 5381;
    while (*s)
        hash = 33 * hash ^ (unsigned char) *s++;
    return hash % SIZE;
}
