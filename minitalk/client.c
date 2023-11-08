/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:39:26 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/10/22 17:25:02 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45)
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

void	send_message(int c, int id)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & (1 << i))
			kill(id, SIGUSR1);
		else
			kill(id, SIGUSR2);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	id;

	if (ac == 3)
	{
		id = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			send_message(av[2][i], id);
			i++;
		}
	}
	return (0);
}
