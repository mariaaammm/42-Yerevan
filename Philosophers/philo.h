/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:03:07 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/12/03 19:15:00 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	time_to_think;
	long long int	time_to_die;
	long long int	last_meal;
	int				is_dead;
	int				eat_count;
	int				index;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}				t_philo;

typedef struct s_thread{
	int				num_of_philos;
	pthread_mutex_t	*fork;
	t_philo			*philo;
	pthread_t		*thread;
}					t_thread;

unsigned long long int	now(void);
void					ft_usleep(long ms);
int						handle(int count, char **av);
int						is_letter(int ac, char **str);
int						ft_atoi(const char *str);
int						create_philo(char **av, t_thread **th);
void					init(int ac, char **av, t_thread **philo);
int						check_is_dead(t_thread **philos);
void					mutex(char **av, t_thread **philos);
void					*actions(void *threads);
void					ft_destroy(t_thread	*philos, char **av);
void					ft_start(t_philo	*philo);

#endif
