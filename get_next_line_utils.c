/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/11/17 09:37:45 by ssukhija          #+#    #+#             */
/*   Updated: 2024/11/17 09:37:45 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		while (s1[i] != '\0')
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_append(char *txt, char *buff)
{
	char	*str;
	int		len;

	len = 0;
	if (buff[0] == '\0')
		return (txt);
	if (txt != NULL)
		len = ft_strlen(txt);
	else
	{
		txt = malloc(1 * sizeof(char));
		if (txt == NULL)
			return (NULL);
		txt[0] = '\0';
		len = ft_strlen(txt);
	}
	str = malloc(((len + ft_strlen(buff)) + 1) * sizeof(char));
	if (str == NULL)
	{
		free(txt);
		return (NULL);
	}
	str = ft_strcpy(str, txt, buff);
	free(txt);
	return (str);
}
