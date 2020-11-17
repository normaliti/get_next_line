/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweeper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:49:45 by lweeper           #+#    #+#             */
/*   Updated: 2020/11/11 12:50:23 by lweeper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *s);

char		*ft_strcpy(char *dst, const char *src);

char		*ft_strdup(const char *s1);

char		*ft_strjoin(char *s1, char *s2);

char		*ft_strchr(const char *s, int c);

int			get_next_line(int fd, char **line);

#endif
