/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:59:20 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/10/05 17:47:22 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(char *str)
{
	int				i;
	long long int	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		if (res < -2147483648 || res > 2147483647)
			return (2147483650);
		i++;
	}
	return (res * sign);
}

int	is_letter(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i])
	{
		if ((str[i][0] != 43 && str[i][0] != 45)
			&& (!(str[i][0] >= 48 && str[i][0] <= 57)))
			return (-1);
		if ((str[i][0] == 43 || str[i][0] == 45) && !str[i][1])
			return (-1);
		j = 1;
		while (str[i][j])
		{
			if (str[i][j] >= 48 && str[i][j] <= 57)
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	repeated(char	**str)
{
	int	i;
	int	j;
	int	n1;
	int	n2;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) == 21474836450)
			return (-1);
		n1 = ft_atoi(str[i]);
		j = i + 1;
		while (str[j])
		{
			n2 = ft_atoi(str[j]);
			if (n1 == n2)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	out_of_range(char	**str)
{
	int				i;
	long long int	n;

	i = 0;
	while (str[i])
	{
		while (*str[i] == '0')
			str[i]++;
		n = ft_atoi(str[i]);
		if (n < -2147483648 || n > 2147483647)
			return (-1);
		i++;
	}
	return (0);
}

void	handling(char **x)
{
	if (is_letter(x) == -1)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	else if (repeated(x) == -1)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	else if (out_of_range(x) == -1)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
}
