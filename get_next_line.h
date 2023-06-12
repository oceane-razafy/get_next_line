/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:19:49 by orazafy           #+#    #+#             */
/*   Updated: 2022/12/03 01:18:19 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1042
# endif
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
ssize_t	ft_strchr(char *str, char c);
char	*ft_get_line(char **result);
char	*ft_strndup(char *str, ssize_t n);
ssize_t	ft_strlen(char *str);
char	*ft_last_line(char **result);
void	ft_free(char **result);

#endif
