/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:05:55 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/05/13 17:57:16 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i;

	i = 1;
	fd = open("file.txt", O_RDONLY);
	while (i != 0)
	{
		printf("%s", get_next_line(fd));
		i--;
	}
	return (0);
}
