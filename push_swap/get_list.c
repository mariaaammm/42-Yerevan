/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:55:36 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/10/05 17:30:02 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_list(char **av)
{
	char	*arg;
	int		i;
	char	**num;		

	i = 1;
	arg = NULL;
	while (av[i])
	{
		if (!arg)
			arg = ft_strdup(av[i]);
		else
		{
			arg = ft_strjoin(arg, " ");
			arg = ft_strjoin(arg, av[i]);
		}
		i++;
	}
	num = ft_split(arg, ' ');
	return (num);
}

t_list	*get_a_stack(char **str)
{
	int		i;
	t_list	*first;
	t_list	*last;
	t_list	*temp;

	i = 1;
	first = (t_list *)malloc(sizeof(t_list));
	if (!first || !str[0])
		return (NULL);
	first->data = ft_atoi(str[0]);
	first->next = NULL;
	last = first;
	while (str[i])
	{
		temp = (t_list *)malloc(sizeof(t_list));
		temp->data = ft_atoi(str[i]);
		temp->next = NULL;
		last->next = temp;
		last = temp;
		i++;
	}
	return (first);
}

t_list	*get_b_stack(void)
{
	return (0);
}

void	rrr(t_data *stack)
{
	rra(stack);
	rrb(stack);
}
