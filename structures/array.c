#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initLength 100

typedef int* list;



typedef struct {
    int length;
    list list;
} array;

array* create( void ) {
    list list;


    array *ar = malloc(sizeof(array));

    ar->length = 0;
    ar->list = malloc(initLength);

    return ar;
}
bool isArrayNeedExpand(array* this) {
    return this->length != 0 && this->length % initLength == 0;
}

void push(array* this, int item) {
    if (isArrayNeedExpand(this)) {
        list newList = malloc(((this->length % initLength) +1) * initLength);
//        copy(this, newList)
    }
    this->list[this->length] = item;

    this->length++;


    // push value and length increment
}

void copy(array* from, array* to) {
    for( int i = 0; i < from->length; i++){
        to->list[i] = from->list[i];
    }
}



int main() {

    // сделать динамический массив

    array* arr = create();

    push(arr, 1);
    push(arr, 2);
    push(arr, 3);



    return 0;
}

