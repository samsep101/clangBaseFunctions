#define charEqual(x, y) x == y

typedef char* string;


short CompareRegex(char input, char pattern) {

    if (pattern == '*' || pattern == '?'){
        return 1;
    }

    if (input == pattern) {
        return 1;
    }

    return 0;
}

short Regex(string input, string pattern) {
    short result = 1;

    while (*input != '\0') {
        // if pattern is specialChar of specialConstruct and previous char not \ do special compare
        // another just compare string

        if (0) {

        }else {
            if (!(charEqual(*input, *pattern))) {
                result = 0;
                break;
            }
        }

        input++;
        pattern++;
    }

    return  result;
}