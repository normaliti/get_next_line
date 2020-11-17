/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweeper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:48:34 by lweeper           #+#    #+#             */
/*   Updated: 2020/11/11 12:48:52 by lweeper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strnew(unsigned int size)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

static void	ft_strclear(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static char	*calc_rem(char **rem, char **line)
{
	char *ptr_n;

	ptr_n = NULL;
	if (*rem)
		if ((ptr_n = ft_strchr(*rem, '\n')))
		{
			*ptr_n = '\0';
			*line = ft_strdup(*rem);
			ptr_n++;
			ft_strcpy(*rem, ptr_n);
		}
		else
		{
			*line = ft_strdup(*rem);
			ft_strclear(&(*rem));
		}
	else
		*line = ft_strnew(0);
	return (ptr_n);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			byte_read;
	static char	*rem[1024];
	char		*ptr_n;
	char		*tmp;

	if ((-1 == read(fd, buf, 0)) || !line || BUFFER_SIZE <= 0 || fd > 1023)
		return (-1);
	ptr_n = calc_rem(&rem[fd], line);
	while (!ptr_n && (byte_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((ptr_n = ft_strchr(buf, '\n')))
		{
			*ptr_n = '\0';
			if (!(rem[fd] = ft_strdup(++ptr_n)))
				return (-1);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(tmp);
	}
	return (ptr_n ? 1 : 0);
}
