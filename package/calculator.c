#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <stdio.h>
#include <math.h>


int charToInt(char symbol) {
    return symbol - '0';
}

#define isNumeric(x) x >= '0' && x <= '9'
#define isMathOperation(char) char == '+'

/**
 * for input: some math expression
 * for example:
 * 1. 1 + 1
 * 2. 2 + (4*1)
 * 3. 5 * (1/8 + 4)
*/

//char* readInput() {
//    printf(">>> ");
//
////    return (char *) fgetc(stdin);
//}

typedef struct expression {
    int *right;
    int *left;
    char operation;
} expression;

typedef expression ast;
//
//int calcAstExpression (ast tree) {
//
//}


//ast readAst(char* readAst) {
//
//    return {
//
//    }
//}


ast *create() {
    ast *tree = malloc(sizeof(ast));

    return tree;
}

//char readNextChar(char* input) {
//
//}


int readNumber(char *input) {
    char c;
    int result = 0;
    int iter = 0;


    while ((c = input[iter++]) != '\0') {
        if (isNumeric(c)) {
//            result += charToInt(c) * ( pow(10, iter));
        }
    }
}


//char readC(){}

ast *parseOperation(char *input) {
    ast *tree = create();
    int iter = 0;
    char c;

    while ((c = input[iter++]) != '\0') {
        if (isNumeric(c)) {
//            result += charToInt(c) * ( pow(10, iter));
        }
    }


    return tree;
}


ast *parseAst(char *input) {
    ast *tree = create();

    char c;
    int i = 0;

    while ((c = input[i++]) != '\0') {

        if (c == '(') {
            // create new node for right or left
        } else if (isNumeric(c)) {
            if (tree->left == NULL) {
                (*tree).left = malloc(sizeof(char));
                *(*tree).left = charToInt(c);

            } else {
                (*tree).right = malloc(sizeof(char));
                *(*tree).right = charToInt(c);
            }
        } else if (isMathOperation(c)) {
            if (tree->right != NULL) {

                // если операция предидущая по приоритету мееньше то что-то там нужно сделать
//                tree
//                parseAst(input + (i-2));

                return tree;
            } else {
                if (tree->left == NULL) {
                    (*tree).left = malloc(sizeof(char));
                    *(*tree).left = 0;
                }

                tree->operation = c;
            }
        }

//        tree[]
    }

    return tree;
}

int calcAst(ast *tree) {
    int result = 0;

    result = *((*tree).left) + *((*tree).right);

//    printf("%d - %d - %c\n", *((*tree).left), *((*tree).right), tree->operation);
    return result;
}

int calc(char *regular) {

    ast *t = parseAst(regular);

    printf("%d\n", calcAst(t));


    return 3;
}


void readNext(char ** input) {

    printf("%c\n", **input);
    *input = *input + 1;
    printf("%c\n", **input);
//    return **(++input);
}

int main() {
    // read input
    // parse input
    // calc input
    // return some
//    char* input;

//    set();




    char *input = "12345";

    char* t = input;

    readNext(&t);
    readNext(&t);

    printf("%s", input);

//    printf("%d", readNumber("123123"));
//
//    return 1;
//    typedef struct {
//        char *input;
//        int result;
//    } scen;




//
//    scen tests[3] = {
//            { "1 + 2",    3},
////            { "3 + 99",   102},
////            {"(1 - 24) / 25 ", 1}
//    };
//
//    for(int i = 0; i < 3; i++) {
//        int result = calc(tests[i].input);
//
//        printf("%s = %d\n", tests[i].input, result);
//    }





//    while((word = getchar()) != EOF) {
//        printf("%c", word);
//    }



    return 0;
}


