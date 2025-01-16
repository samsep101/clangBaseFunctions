#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* left;
    struct node* right;
    void* value;

} node;


node* createNode(void* value){
    node* n = malloc(sizeof(node));

    n->value = value;

    return n;
}


int main() {

    printf("Size %c", 1);

    return 1;
}


/*
 * find
 * push
 * remove
 *
 * create
 * normalize
 *
 */