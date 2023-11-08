/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:55:20 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/13 17:04:43 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*detect_line(int fd, long readsize, char *st_line)
{
	char	buffer[BUFFER_SIZE + 1];

	while (1)
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		buffer[readsize] = '\0';
		if (readsize == -1)
			return (NULL);
		if (!st_line)
			st_line = ft_strdup(buffer); 
		else
			st_line = ft_strjoin(st_line, buffer);
		if (ft_strchr(buffer, '\n') || readsize == 0)
			break ;
	}
	return (st_line);
}

char	*get_next_line(int fd)
{
	static char	*st_line;
	long		readsize;
	long		length;
	char		*line;
	char		*temp;

	readsize = 1;
	st_line = detect_line(fd, readsize, st_line);
	length = ft_strlen(st_line) - ft_strlen(ft_strchr(st_line, '\n')) + 1;
	line = ft_substr(st_line, 0, length);
	temp = st_line;
	st_line = ft_substr(st_line, length, ft_strlen(st_line));
	free(temp);
	return (line);
}
