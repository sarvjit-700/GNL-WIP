
#include <fcntl.h>      // For open
#include <stdio.h>      // For printf
#include <stdlib.h>     // For exit
#include "get_next_line.h"

int main(void)
{
    char *line;
    char *file;
   // int i = 0;
    //int fd = open("alternate_line_nl_with_nl", O_RDONLY);
    file = "../get_next_line/files/big_line_no_nl";
    int fd = open(file, O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file"); /// return null
        return (1);
    }


	printf("fd is : %s\n", file);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("**************Line: %s", line);
        free(line); // Free the line after each read

    }       

    close(fd);
    return (0);
}
