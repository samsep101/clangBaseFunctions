#include <stdlib.h>
#include <stdio.h>
#define isOpenScope(c) c == '('
#define isCloseScope(c) c == ')'
#define isOpenArray(c) c == '['
#define isCloseArray(c) c == ']'
#define null 0
#define isOpenObject(c) c == '[' || c == '('
#define isCloseObject(c) c == '}' || c == ')'

struct {
    unsigned isScope: 1;
    unsigned isArray: 1;
} typeEnum;


typedef struct data {
    int type;
    void* data;
} data;


typedef struct scope {
    void* data;
    struct {
        unsigned isScope: 1;
        unsigned isArray: 1;
    } type;
} scope;










struct scope* readScope(char* string, int* index) {
    char c;
    struct scope* object = NULL;

    printf("read scope: %s\n", string);
    printf("read scope start index: %d\n", *index);
    printf("read scope start char: %c\n", string[*index]);


    while((c = string[*index]) != '\0') {
        printf("new circe with char %c\n", c);

        if (isOpenScope(c)) {
            printf("scope opened: %d - %c\n", *index, string[*index]);
            if (object == NULL) {
                printf("main scope obj initialization;\n");
                object = malloc(sizeof(scope));
                (*object).data = NULL;
                object->type.isScope = 1;
            }else if(object != NULL) {
                printf("find new scope: read deep scope: %d;\n", *index);

                int s = (int) readScope(string, index);


                if ((void *) s == NULL) {
                    return NULL;
                }


                object->data = (void *) s;
            }

//            if (scope == null) {
//                scope = malloc(sizeof (scope));
//            }
        }


        if (isOpenArray(c)) {
            printf("array opened: %d - %c\n", *index, string[*index]);
            if (object == NULL) {
                printf("main array obj initialization;\n");
                object = malloc(sizeof(scope));
                (*object).data = NULL;
                object->type.isArray = 1;
            }else if(object != NULL) {
                printf("find new scope: read deep scope: %d;\n", *index);

                int s = (int) readScope(string, index);


                if ((void *) s == NULL) {
                    return NULL;
                }


                object->data = (void *) s;
            }
        }


        if (isCloseArray(c)) {
            printf("scope closing: %d - %c\n", *index, string[*index]);

            if (object == NULL || object->type.isArray != 1) {
                printf("scope closing error - not initializated: %d - %c\n", *index, string[*index]);
                return NULL;
            }

            return object;
        }

        if (isCloseScope(c)) {
            // close scope
            printf("scope closing: %d - %c\n", *index, string[*index]);

            if (object == NULL || object->type.isScope != 1) {
                printf("scope closing error - not initializated: %d - %c\n", *index, string[*index]);
                return NULL;
            }

            return object;
        }

        (*index)++;
    }


    return NULL;
}


int parse(char* string) {
    int index = 0;
    char c;
    struct data* object = malloc(sizeof(data));


    printf("start parse: %s\n", string);

    while((c = string[index]) != '\0') {
        printf("New char %c at index %d\n", string[index], index);

        if (isOpenObject(c)) {
            object->type = typeEnum.isArray;
//            object->data = malloc(sizeof(int*));
            scope *s = readScope(string, &index);

            if (s == NULL) {
                return 1;
            }
        }else if (isCloseObject(c)) {
            return 2;
        } else {
            return 3;
        }

        index++;
    }

    return 0;
}


int main() {

    char string[] = "[()()([()](()))]";
    int index = 0;
    char c;

    int res = parse(string);


    printf("%d", res);
    // read char
    
    return 0;
}