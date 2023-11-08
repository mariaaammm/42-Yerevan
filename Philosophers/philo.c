/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:52:13 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/12/04 14:07:17 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(int ac, char **av, t_thread **ph)
{
	t_thread	*philos;
	int			i;

	philos = *ph;
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos->num_of_philos = ft_atoi(av[1]);
		philos->philo[i].time_to_die = ft_atoi(av[2]);
		philos->philo[i].time_to_eat = ft_atoi(av[3]);
		philos->philo[i].time_to_sleep = ft_atoi(av[4]);
		philos->philo[i].index = i + 1;
		if (av[5])
			philos->philo[i].eat_count = ft_atoi(av[5]);
		else
			philos->philo[i].eat_count = -1;
		i++;
	}
}

int	check_is_dead(t_thread **th)
{
	t_thread		*philos;
	int				i;
	long long int	time;

	philos = *th;
	i = 0;
	while (1)
	{
		time = now();
		if (time - philos->philo[i].last_meal >= philos->philo[i].time_to_die)
		{
			printf("%llu Philosopher %d died ❌\n",
				time - philos->philo[i].last_meal, philos->philo[i].index);
			return (1);
		}
		if (philos->philo->eat_count == 0)
			return (1);
	}
	return (0);
}
