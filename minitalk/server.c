/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:56:24 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/10/24 17:28:51 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	handler(int sig)
{
	static unsigned char	x;
	static int				i;

	++i;
	x = x << 1;
	if (sig == SIGUSR1)
		x = x | 1;
	if (i == 8)
	{
		write(1, &x, 1);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("The id is ");
	ft_putnbr(getpid());
	ft_putstr(" ");
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
