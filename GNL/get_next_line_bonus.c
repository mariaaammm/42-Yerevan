/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:55:20 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/15 14:29:22 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*detect_line(int fd, long readsize, char *sline)
{
	char	buffer[BUFFER_SIZE + 1];

	while (1)
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		buffer[readsize] = '\0';
		if (readsize == -1)
			return (NULL);
		if (!sline)
			sline = ft_strdup(buffer);
		else
			sline = ft_strjoin(sline, buffer);
		if (ft_strchr(buffer, '\n') || readsize == 0)
			break ;
	}
	return (sline);
}

char	*get_next_line(int fd)
{
	static char	*sline[OPEN_MAX];
	long		readsize;
	long		length;
	char		*line;
	char		*temp;

	readsize = 1;
	sline[fd] = detect_line(fd, readsize, sline[fd]);
	length = ft_strlen(sline[fd]) - ft_strlen(ft_strchr(sline[fd], '\n')) + 1;
	line = ft_substr(sline[fd], 0, length);
	temp = sline[fd];
	sline[fd] = ft_substr(sline[fd], length, ft_strlen(sline[fd]));
	free(temp);
	return (line);
}
