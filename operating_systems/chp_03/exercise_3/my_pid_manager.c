#include <stdio.h>
#include <stdlib.h>


// Macros to identify the range
// of possible pid values:
#define MIN_PID 300
#define MAX_PID 5000
#define BITS (MAX_PID - MIN_PID)

// Macros for defining Active and In-Active processes
#define ACTIVE 1
#define INACTIVE 0


// Bit-field struct
struct PID_BITFIELD
{
    u_int8_t bit : 1; //<--- 1 bit in size
};

// Create Static Bit-Field Instance
static struct PID_BITFIELD pids_bits[BITS];



// Function protoypes
int allocate_map();
int allocate_pid();
void release_pid(int pid);


// My header file for manipulating the bit field.
// Functions include "Set-bit", "Check-bit"... etc.
#include "my_pid_manager.h"

int main()
{
    if ( allocate_map() == -1 )
    {
        printf("Error creating PID Bit-field");
        return EXIT_FAILURE;
    }



    // implicit truncation from 'int' to bit-field changes value from 2 to 0 [-Wbit/field-constant-conversion]
    // Above comment warnings occur if you change below right side equals values to 2 and 3 respectively
    // Use flag -Werror to convert warnings into compile time errors.



    
    // Print out entire bit-field
    for (uint index = 0; index < BITS; index++)
    {
        if (index % 55 == 0) printf("\n");

        // ----------------------Print Backwards
        printf( "%u ", pids_bits[BITS - index - 1].bit );
    }

    printf("\n\n");







    
    return EXIT_SUCCESS;
}


// Create Data-Structure that will hold
// Process ID's and their availability
int allocate_map()
{
    if (pids_bits == NULL)
        return -1;
    

    for (uint i = 0; i < MAX_PID - MIN_PID + 1; i++)
    {
        pids_bits[i].bit = INACTIVE;
    }

    return 1;
}


// Check to see if there's an available process ID,
// then assign the process an ID if there is one available.
int allocate_pid()
{
    for (uint i = 0; i < BITS; i++)
    {
        if (1)
        {
            // pId[i].isAvailable = FALSE;
            return MIN_PID + i;
        }
    }

    return -1;
}

