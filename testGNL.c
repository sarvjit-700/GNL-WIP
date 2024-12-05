
#include <fcntl.h>      // For open
#include <stdio.h>      // For printf
#include <stdlib.h>     // For exit
#include "get_next_line.h"

int main(void)
{
    char *line;
    char *file;
    
    file = "../EVALS/testfiles/only_nl.txt";
    int fd = open(file, O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file"); /// return null
        return (1);
    }


	printf("fd is : %s\n", file);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("***Line: %s", line);
        free(line); // Free the line after each read

    }       

    close(fd);
    return (0);
}
