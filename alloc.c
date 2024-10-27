#define null 0
#define allocateSize 1000


static char buffer[allocateSize];
static char *bufferPointer = buffer;

char* alloc(int n) {
    if (bufferPointer + n <= buffer + allocateSize) {
        bufferPointer += n;

        return bufferPointer - n;
    }else {
        return null;
    }
}


void free(char *p) {
    if (p >= buffer && p < buffer + allocateSize) {
        bufferPointer = p;
    }
}
