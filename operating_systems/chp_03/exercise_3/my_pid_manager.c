#include <stdio.h>
#include <stdlib.h>

/*
*  An operating system's pid manager is responsible for managing process identifiers. When a process
*  is first created, it is assigned a unique pid by the pid manager. The pid is returned to the pid
*  manager when the process completes execution, and the manager may later reassign this pid. Process
*  identifiers are discussed more fully in Section Process creation. What is most important here is to
*  recognize that process identifiers must be unique; no two active processes can have the same pid.
* -----------------------------------------------------------------------------------------------------------
*  You may use any data structure of your choice to represent the availability of process identifiers.
*  One strategy is to adopt what Linux has done and use a bitmap in which a value of 0 at position
*  indicates that a process id of value  is available and a value of 1 indicates that the process id is currently in use.
* -----------------------------------------------------------------------------------------------------------
*  int allocate_map(void) — Creates and initializes a data structure for representing pids; returns −1 if unsuccessful, 1 if successful
*  int allocate_pid(void) — Allocates and returns a pid; returns −1 if unable to allocate a pid (all pids are in use)
*  void release_pid(int pid) — Releases a pid.
*/


// Macros to identify the range
// of possible pid values:
#define MIN_PID 300
#define MAX_PID 5000
#define BITS ( MAX_PID - MIN_PID + 1 )

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



int main()
{
    // Testing my Code...
    if ( allocate_map() == -1 )
    {
        printf("Error creating PID Bit-field");
        return EXIT_FAILURE;
    }
    
    
    int pid;

    if ((pid = allocate_pid()) != -1)
        printf("New Process Allocated Pid = %d \n", pid);
    if ((pid = allocate_pid()) != -1)
        printf("New Process Allocated Pid = %d \n", pid);
    if ((pid = allocate_pid()) != -1)
        printf("New Process Allocated Pid = %d \n", pid);
    if ((pid = allocate_pid()) != -1)
        printf("New Process Allocated Pid = %d \n", pid);


    printf("Now Releasing Process # %d\n", pid);
    release_pid(pid);

    if ((pid = allocate_pid()) != -1)
        printf("New Process Allocated Pid = %d \n", pid);
    // Finished testing...

    
    return EXIT_SUCCESS;
}


// Create Data-Structure that will hold
// Process ID's and their availability
int allocate_map()
{
    if (pids_bits == NULL)
        return -1;
    

    for (uint i = 0; i < BITS; i++)
    {
        pids_bits[i].bit = INACTIVE;
    }

    return 1;
}


// Check to see if there's an available process ID,
// then assign the process an ID if there is one available.
int allocate_pid()
{
    for (uint index = 0; index < BITS; index++)
    {
        // Check if the available index has an available assignable PID
        if( (pids_bits[index].bit) == INACTIVE )
        {
            pids_bits[index].bit = ACTIVE;
            return index + MIN_PID;
        }
    }

    return -1;
}


// Process finished executing and is
// returning the PID back to the manager
void release_pid(int pid)
{
    pids_bits[pid - MIN_PID].bit = INACTIVE;
}
