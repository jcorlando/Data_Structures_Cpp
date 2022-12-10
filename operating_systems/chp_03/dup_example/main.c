#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int fd = open("out.txt", O_WRONLY| O_TRUNC | O_CREAT, 0777);

    /* Save current stdout for use later */
    int terminal_stdout_fd = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);

    /* Print to out.txt */
    fprintf(stdout, "\nThis prints to \"out.txt\"\n\n");
    fflush(stdout);

    /* Restore Terminal stdout */
    dup2(terminal_stdout_fd, STDOUT_FILENO);
    close(terminal_stdout_fd);

    /* Print to terminal */
    fprintf(stdout, "\nThis prints to Terminal\n\n");
    fflush(stdout);

    close(fd);

    return EXIT_SUCCESS;
}
