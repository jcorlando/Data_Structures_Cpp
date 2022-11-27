#ifndef CIRCULARBUFFER_C
#define CIRCULARBUFFER_C

struct CircularBuffer
{
    uint size;
    uint head;
    char history[MAXHIST][MAXLENCOMM];
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

// void printHistoryList(struct CircularBuffer *commandHistory)
// {
//     printf("\n\n\n");
//     fflush(stdout);
//     for (uint i = commandHistory->size; i > 0; i--)
//     {
//         // ---------- Iterate Backwards to Display History -------------
//         uint indexToPrint = commandHistory->head - i;
//         char *printString = commandHistory->history[indexToPrint];
//         printf( "\nRecent Commands List # %d  ==  %s", (i-1), printString );
//     }
//     printf("\n\n\n");
//     fflush(stdout);
// }

#endif // CIRCULARBUFFER_C
