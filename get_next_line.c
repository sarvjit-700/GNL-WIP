/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:39:12 by ssukhija          #+#    #+#             */
/*   Updated: 2024/11/18 09:39:12 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_find_newline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_read(int fd, char *txt)
{
	char	*buff;
	int		num_chars;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	num_chars = 1;
	while ((num_chars != 0) && (ft_find_newline(txt) < 0))
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

char	*ft_keep(char *s)
{
	char	*keep;
	int		i;
	int		x;

	i = 0;
	if (s == NULL || s[0] == '\0')
		return (NULL);
	x = ft_find_newline(s);
	if (x == -1)
		x = ft_strlen(s);
	keep = malloc((x + 2) * sizeof(char));
	if (keep == NULL)
		return (NULL);
	while (i <= x)
	{
		keep[i] = s[i];
		i++;
	}
	keep[i] = '\0';
	return (keep);
}

char	*ft_rest(char *s, int x)
{
	char	*rest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[x + 1] != '\0')
	{
		len++;
		x++;
	}
	x = ft_find_newline(s);
	rest = malloc((len + 1) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	while (s[x + i + 1] != '\0')
	{
		rest[i] = s[x + i + 1];
		i++;
	}
	rest[i] = '\0';
	free(s);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*txt;
	char		*keep;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	txt = ft_read(fd, txt);
	if (!txt)
		return (NULL);
	keep = ft_keep(txt);
	x = ft_find_newline(txt);
	if (x == -1)
	{
		free(txt);
		txt = NULL;
		return (keep);
	}
	else
		txt = ft_rest(txt, x);
	return (keep);
}
