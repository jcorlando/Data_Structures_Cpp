#ifndef WORKLOAD_H
#define WORKLOAD_H

// My Macros
#define NUM_TASKS 2 // <- Number of tasks you want to create

void WORKLOAD(long &a)
{
  // Fork first process and get parent process ID
  pid_t pid = fork();
  pid_t ppid = 0;
  if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");
  if(pid > 0) ppid = getpid();

  // Create the required number of additional processes
  for(uint i = 2; i < NUM_TASKS; i++)
  {
    if(pid == 0) pid = fork();
    if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");
  }


  // for(long i = 0; i < N; ++i)  (*a)++;


  std::cout << "pid is : " << getpid() << std::endl;
  // Kill all child processes
  if(pid != ppid) exit(0);
}

#endif // WORKLOAD_H