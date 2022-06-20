#include <stdio.h>
#include <stdlib.h>

// Constants to identify the range of
// possible pid values:
#define MIN_PID 300
#define MAX_PID 5000


#define BITS 4
static struct PID_BITFIELD
{
    unsigned bit : 1;
} active_pids[BITS];

// Function protoypes
int allocate_map();
int allocate_pid();
void release_pid(int pid);


int main()
{
    active_pids[0].bit = 0;
    active_pids[1].bit = 1;
    // implicit truncation from 'int' to bit-field changes value from 2 to 0 [-Wbit/field-constant-conversion]
    // Above comment warnings occur if you change below right side equals values to 2 and 3 respectively
    active_pids[2].bit = 2;
    active_pids[3].bit = 3;

    int i;
    for ( i=0; i < BITS ; i++)
    {
        printf("bit of bit %i is %u\n", i, active_pids[i].bit);
    }

    printf( "\nSize of bit is  ==>  %lu\n\n", sizeof(active_pids) );


    return EXIT_SUCCESS;
}
