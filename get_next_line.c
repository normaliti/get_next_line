/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweeper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:35:34 by lweeper           #+#    #+#             */
/*   Updated: 2020/11/08 12:35:37 by lweeper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"



char	*ft_strnew(size_t size)
{
	char *str;
	if(!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while(size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

void	ft_strclear(char *str)
{
	if (str != NULL)
		{
			free(str);
			//str = NULL;
		}
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;	
	while (src)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}	

char	*calc_rem(char *rem, char **line)
{
	char *ptr_n;

	ptr_n = NULL;		
	if (rem)
	{	
		if((ptr_n =ft_strchr(rem, '\n')))
		{
			*ptr_n = '\0';
			*line = ft_strdup(rem);
			ptr_n++;
			ft_strcpy(rem, ptr_n);
		}
		else
		{
			*line = ft_strdup(rem);
			ft_strclear(rem);
		}
	}		
	else
		*line = ft_strnew(1);
	return (ptr_n);
}

int	get_next_line(int fd, char **line)
{
	char	buf[11];
	int		byte_read;
	static char	*rem;
	char	*ptr_n;
	char	*tmp;
	
	ptr_n = calc_rem(rem, line);
	while(!ptr_n && (byte_read = read(fd, buf, 10)))
	{
		buf[byte_read] = '\0';		
		if ((ptr_n =ft_strchr(buf, '\n')))
		{
			*ptr_n = '\0';
			ptr_n++;
			rem = ft_strdup(ptr_n);		
		}
		
		tmp = *line;		
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}	
	return (0);
}


int main (void)
{
	char	*line;
	int		fd;
	
	//line = "hello, world";	
	fd = open("text.txt", O_RDONLY);
	//fd = 1;
	printf("id = %d\n", fd);
	get_next_line(fd, &line);
	printf("%s\n\n", line);

	get_next_line(fd, &line);
	printf("%s\n\n", line);

	//get_next_line(fd, &line);
	//printf("%s\n\n", line);
	
	return (0);
}
