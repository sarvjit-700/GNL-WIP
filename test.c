// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include "get_next_line.h"

// int	main()
// {
// 	int	fd;
// 	//int	chars_read;
// 	//char	buf[256];


	
// 	fd = open("testfile.txt", O_RDWR);
// 	print("here fd is %d/n", fd);
// 	get_next_line(fd);

//  	// while ((chars_read = read(fd, buf, 8)))
// 	// {
// 	// 	buf[chars_read] = '\0';
// 	// 	printf("buf -> %s\n", buf);
// 	// }
// 	return (0);
// }

#include <fcntl.h>      // For open
#include <stdio.h>      // For printf
#include <stdlib.h>     // For exit
#include "get_next_line.h"

int main(void)
{
    char *line;
    char *file;

    file = "../files/empty";

   // int i = 0;
    //int fd = open("alternate_line_nl_with_nl", O_RDONLY);
    int fd = open(file, O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening file"); /// return null
        return (1);
    }


	printf("file is : %s\n", file);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("**************Line: %s", line);
        free(line); // Free the line after each read

    }       

    close(fd);
    return (0);
}