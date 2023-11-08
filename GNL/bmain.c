/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:29:06 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/13 19:36:06 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd1;
	int	fd2;
	int	i;

	i = 5;
	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	while (i != 0)
	{
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd2));
		i--;
	}
	return (0);
}
