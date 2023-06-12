/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:17:59 by orazafy           #+#    #+#             */
/*   Updated: 2022/12/03 15:46:34 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*result;
	ssize_t		nb;
	char		buf[BUFFER_SIZE + 1];

	if (result == 0)
		result = ft_strndup("\0", 0);
	if (result == NULL)
		return (NULL);
	nb = read(fd, buf, BUFFER_SIZE);
	while (nb >= 0)
	{
		buf[nb] = 0;
		result = ft_strjoin(result, buf);
		if (result == NULL)
			return (NULL);
		if (nb == 0 && result[0] == 0)
			break ;
		if (ft_strchr(result, '\n') == 1)
			return (ft_get_line(&result));
		if (nb == 0)
			return (ft_last_line(&result));
		nb = read(fd, buf, BUFFER_SIZE);
	}
	ft_free(&result);
	return (NULL);
}

void	ft_free(char **result)
{
	free(*result);
	*result = NULL;
}

char	*ft_get_line(char **result)
{
	char		*line;
	char		*str;
	char		*reminder;
	ssize_t		i;

	str = ft_strndup(*result, ft_strlen(*result));
	if (str == NULL)
		return (NULL);
	ft_free(result);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_strndup(str, i + 1);
	if (line == NULL)
		return (NULL);
	reminder = ft_strndup(str + i + 1, ft_strlen(str + i + 1));
	if (reminder == NULL)
		return (NULL);
	free(str);
	*result = reminder;
	return (line);
}

char	*ft_last_line(char **result)
{
	char	*line;

	line = ft_strndup(*result, ft_strlen(*result));
	ft_free(result);
	return (line);
}
