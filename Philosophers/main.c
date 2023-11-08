/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:08:18 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/12/04 14:44:00 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy(t_thread	*philos, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_destroy(&philos->fork[i]);
		i++;
	}
	free(philos->fork);
	free(philos->philo);
	free(philos->thread);
	free(philos);
}

int	main(int ac, char **av)
{
	t_thread	*philos;
	int			i;

	if (handle(ac, av) == -1 || is_letter(ac, av) == -1)
		return (-1);
	i = 0;
	philos = malloc(sizeof(t_thread));
	philos->philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	philos->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_init(&philos->fork[i], NULL);
		i++;
	}
	init(ac, av, &philos);
	mutex(av, &philos);
	if (create_philo(av, &philos) == 1)
		return (1);
	return (0);
}
