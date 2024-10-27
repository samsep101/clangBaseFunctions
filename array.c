#include <stdlib.h>

#define initLength 1000

typedef int list[initLength];

struct array {
    int length;
    void* list;
};

struct array* create( void ) {
    list list;

    struct array ar = {
        initLength, list
    };

    return &ar;
}

void push() {



}

