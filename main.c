#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "hashmap.c"



int main(void) {
    printf("%u\n", doHash("Hellow "));

    set("hello", "world");
    printf("%d\n", has("hello"));
    printf("%d\n", has("h1ello"));

    set("hello", "sdf");

    printf("my string by key: %s", get("hello"));

    return EXIT_SUCCESS;
}
