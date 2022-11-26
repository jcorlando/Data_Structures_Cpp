#ifndef CIRCULARBUFFER_C
#define CIRCULARBUFFER_C

// Typedefs & Macros
#define MAXHIST 64

struct CircularBuffer
{
    char prevCommand[1024];
    char *history[1024];
};

#endif // CIRCULARBUFFER_C
