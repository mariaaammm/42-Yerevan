/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:37:56 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/12/03 19:11:50 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex(char **av, t_thread **ph)
{
	t_thread	*philos;
	int			i;

	philos = *ph;
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos->philo[i].left = &philos->fork[i];
		if (i == 0)
			philos->philo[i].right = &philos->fork[ft_atoi(av[1]) - 1];
		else
			philos->philo[i].right = &philos->fork[i - 1];
		i++;
	}
}

void	*actions(void *threads)
{	
	t_philo				*philo;
	unsigned long long	time;

	philo = threads;
	time = now();
	philo->last_meal = time;
	ft_start(philo);
	while (philo->eat_count)
	{
		pthread_mutex_lock(philo->left);
		printf("%llu Philo %d took left fork\n", now() - time, (*philo).index);
		philo->last_meal = now();
		pthread_mutex_lock(philo->right);
		printf("%llu Philo %d took right fork\n", now() - time, (*philo).index);
		printf("%llu Philo %d started eating 🍝\n", now() - time, (*philo).index);
		ft_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		printf("%llu Philo %d is sleeping 💤\n", now() - time, (*philo).index);
		ft_usleep(philo->time_to_sleep);
		printf("%llu Philo %d is thinking 🤔\n", now() - time, (*philo).index);
		if (philo->eat_count != -1)
			philo->eat_count--;
	}
	return (NULL);
}

void	ft_start(t_philo *philo)
{
	if ((*philo).index % 2 == 0)
		ft_usleep(100);
}

int	create_philo(char **av, t_thread **philos)
{
	t_thread	*th;
	int			i;

	th = *philos;
	i = -1;
	th->thread = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	while (++i < ft_atoi(av[1]))
	{
		pthread_create(&(th->thread[i]), NULL, (void *)actions,
			&(th->philo[i]));
		usleep(10);
	}
	if (check_is_dead(&th) == 1)
		ft_destroy(th, av);
	return (0);
}
