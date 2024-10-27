#define is_int(x) x >= '0' && x <= '9'
#define printInt(x) printf("%d\n", x)

int charToInt(char symbol) {
    return symbol - '0';
}

int stringToInt(char string[]) {
    int result = 0;

    while (*string != '\0'){
        if (is_int(*string)) {
            result *= 10;
            result += charToInt(*string);
        }

        string++;
    }

    return result;
}