#include <string.h>
#include "murmur.h"

#define mm_seed 0
#define hashMapLength 100




uint32_t doHash(char *key) {
    uint32_t seed = 0;

    return murmurhash(key, strlen(key), mm_seed) % hashMapLength;
}

struct hashMapValue {
    uint32_t hash;
    char* value;
};

typedef struct hashMapValue hashMap[hashMapLength];

hashMap map;

int set(char *key, char *value) {
    uint32_t hash = murmurhash(key, strlen(key), mm_seed);
    int index = hash % hashMapLength;

    struct hashMapValue * someValue = map+index;

    if (!someValue->value || (hash == someValue->hash)) {
        someValue->hash = hash;
        someValue->value = value;
        return EXIT_SUCCESS;

    }


    printf("collision");


    return -1;
}




int has(char *key) {
    uint32_t index = doHash(key);

    return map[index].value != NULL;
}



char* get(char *key) {
    uint32_t index = doHash(key);

    return map[index].value;
}

