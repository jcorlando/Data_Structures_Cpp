#ifndef CIRCULARBUFFER_C
#define CIRCULARBUFFER_C

struct CircularBuffer
{
    uint size;                          // <-- Current History List Size
    uint head;                          // <-- Index To Insert Next
    char history[MAXHIST][MAXLENCOMM];  // <-- History List <String>
};

void addEntry(struct CircularBuffer *commandHistory, char *string)
{
    strcpy(commandHistory->history[commandHistory->head], string);
    if( commandHistory->size < MAXHIST ) {
        commandHistory->size++;
    }
    commandHistory->head++;
    if( commandHistory->head > (MAXHIST - 1) ) {
        commandHistory->head = 0;
    }
}

#endif // CIRCULARBUFFER_C
