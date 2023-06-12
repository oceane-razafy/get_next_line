/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:42:56 by orazafy           #+#    #+#             */
/*   Updated: 2022/12/03 01:13:39 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	len1;
	ssize_t	len2;
	char	*dest;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		dest[i++] = str2[j++];
	}
	dest[i] = 0;
	ft_free(&str1);
	return (dest);
}

ssize_t	ft_strchr(char *str, char c)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup(char *str, ssize_t n)
{
	char		*dest;
	ssize_t		i;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
