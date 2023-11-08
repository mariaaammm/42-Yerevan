/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:47:48 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/10/01 14:33:02 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly_a_to_b(t_data *stack)
{
	t_list	*a;
	int		i;
	int		counter;

	a = stack->a;
	i = 0;
	counter = counter_count(list_size(stack->a));
	while (a)
	{
		if (a->index <= i)
		{
			pb(stack);
			rb(stack);
			i++;
		}	
		else if (a->index <= counter + i)
		{
			pb(stack);
			i++;
		}
		else
			ra(stack);
		a = stack->a;
	}
}

int	counter_count(int size)
{
	int	counter;

	counter = 0;
	if (size <= 100)
		counter = size * 7 / 100;
	else
		counter = size * 10 / 100;
	return (counter);
}

void	butterfly_b_to_a(t_data *stack)
{
	int		i;
	int		size;
	t_list	*b;

	i = 0;
	size = list_size(stack->b);
	b = stack->b;
	do_b_to_a(i, size, stack, b);
}

void	do_b_to_a(int i, int size, t_data *stack, t_list *b)
{
	while (i < size)
	{
		if (b->index == find_max(stack))
		{
			pa(stack);
			b = stack->b;
		}
		else
		{
			while (b->index != find_max(stack))
			{
				if (above_or_below(stack) == 1)
					rb(stack);
				else
					rrb(stack);
				b = stack->b;
			}
			pa(stack);
			b = stack->b;
		}
		i++;
	}
}
