/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:25:45 by ssukhija          #+#    #+#             */
/*   Updated: 2024/11/11 18:25:45 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *new_str, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 != NULL)
	{
		printf("here if txt is not NULL so FIRST COPY DONE.\n");
		while (s1[i] != '\0')
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
	{
		printf("COPYING BUFF TO STR \n");
		new_str[i+j] = s2[j];
		j++;
	}
	new_str[i+j] = '\0';
	return (new_str);
}

char    *ft_append(char *txt, char *buff)
{
    char    *str;
    int     len;

    len = 0;
    //might need if buff == NULL for empty files?
    if (buff[0] == '\0')
        return (txt);
    if (txt != NULL)
        len = ft_strlen(txt);
    str = malloc(((len + ft_strlen(buff)) + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    //str = ft_strmycpy(str, txt, buff);
    str = ft_strcpy(str, txt, buff);
    // do i need to free txt here
    return (str);
}

int		ft_find_newline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			//printf("found new line\n");
			return (i);
		}
		i++;
	}
	return (-1);
}

char    *ft_read(int fd, char *txt)
{
    char    *buff;
    int     num_chars;
 //   int tmp = 0;

    buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
    if (buff == NULL)
        return (NULL);
    num_chars = 1;
    while ((num_chars != 0) && (ft_find_newline(txt) < 0))  //WHEN THERE IS NOTHING LEFT TO READ AND NO NEWLINE, GET OUT
    //while (num_chars != 0)
    {
        num_chars = read(fd, buff, BUFFER_SIZE);
        if (num_chars == -1)
        {
            free(buff);
            free(txt);
            return (NULL);
        }
        buff[num_chars] = '\0';
        txt = ft_append(txt, buff);
    }
    free(buff);
    return (txt);
}

char    *ft_keep(char *s)
{
    char    *keep;
  //  int len;
    int i;
    int x;
   // char    *str;

// x = -1 means there is no new line but file is EOF
// x = 0 means new line is in pos 0
    i = 0;
    x = ft_find_newline(s);
    if (x == -1)
    {
        printf("x= %d\n", x);
        x = ft_strlen(s);  //end of file 
        printf("s= %s, x= %d\n", s, x);
    }
    keep = malloc ((x + 1) * sizeof(char));
    if (keep == NULL)
        return (NULL);
    while (i < x)
    {
        keep[i] = s[i];
        i++;
    }
    keep[i] = '\0';
    free(s);
    return (keep);

}

char    *ft_rest(char *s)
{   
    //IF NEW LINE IN TXT - SAVE AFTERS HERE TO TXT,  OTHERWISE NULL
    s = NULL;
    return (s);
}

char	*get_next_line(int fd)
{
    static char *txt;
    char    *keep;
   // int x;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    txt = ft_read(fd, txt);
    printf("done with READ\n");
    if (txt == NULL)
        return (NULL);
    printf("going to KEEP\n");
    keep = ft_keep(txt);
    txt = ft_rest(txt);  
 //   x = ft_find_newline(keep);
    
 //   if (x == -1)  //no newlines in malloc' d txt
   //     return (keep);  //keep only up to newline

    return (keep);
}