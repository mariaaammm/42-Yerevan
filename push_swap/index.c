/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:15 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/10/04 19:47:02 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_list *list)
{
	int	size;

	size = 0;
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}

int	find_max(t_data *stack)
{
	int		max;
	t_list	*max_from_b;

	max = 0;
	max_from_b = stack->b;
	while (max_from_b)
	{
		if (max < max_from_b->index)
			max = max_from_b->index;
		max_from_b = max_from_b->next;
	}
	return (max);
}

int	above_or_below(t_data *stack)
{
	int		i;
	t_list	*max;

	i = 0;
	max = stack->b;
	while (max->index != find_max(stack))
	{
		i++;
		max = max->next;
	}
	if (i <= list_size(stack->b) / 2)
		return (1);
	else
		return (-1);
}

void	loop(t_data *stack, t_list *first, t_list *min)
{
	int	i;
	int	size;

	i = 0;
	size = list_size(stack->a);
	while (i < size)
	{
		min = first;
		while (min)
		{
			if (min->index != -1)
				min = min->next;
			else
				break ;
		}
		while (first)
		{
			if (first->data < min->data && first->index == -1)
				min = first;
			first = first->next;
		}
		min->index = i++;
		first = stack->a;
	}
}

void	indexing(t_data *stack)
{
	t_list	*first;
	t_list	*min;

	first = stack->a;
	min = first;
	while (first)
	{
		first->index = -1;
		first = first->next;
	}
	first = stack->a;
	loop(stack, first, min);
}
