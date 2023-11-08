/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:42:12 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/10/01 14:33:41 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nodes(t_data *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->a;
	second = stack->a->next;
	last = stack->a->next->next;
	if (sorted_initially(first) == 1)
		return ;
	else if (first->index < second->index && first->index < last->index)
	{
		rra(stack);
		sa(stack);
	}
	else if (first->index < second->index && first->index > last->index)
		rra(stack);
	else if (first->index > second->index && first->index < last->index)
		sa(stack);
	else
	{
		ra(stack);
		if (second->index > last->index)
			sa(stack);
	}
}

void	push_3_nodes(t_data *stack, t_list *node)
{
	if (sorted_initially(node) == 0)
	{
		pb(stack);
		three_nodes(stack);
		pa(stack);
	}
}

void	four_nodes(t_data *stack, int n)
{
	t_list	*first;
	int		i;

	first = stack->a;
	i = 0;
	while (first)
	{
		if (first->index == n)
			break ;
		i++;
		first = first->next;
	}
	first = stack->a;
	while (first->index != n)
	{
		if (i < 2)
			ra(stack);
		else
			rra(stack);
		first = stack->a;
	}
	push_3_nodes(stack, first);
}

void	push_4_nodes(t_data *stack, t_list *node)
{
	if (sorted_initially(node) == 0)
	{
		pb(stack);
		four_nodes(stack, 1);
		pa(stack);
	}
}

void	five_nodes(t_data *stack)
{
	int		i;
	t_list	*first;

	i = 0;
	first = stack->a;
	while (first)
	{
		if (first->index == 0)
			break ;
		i++;
		first = first->next;
	}
	first = stack->a;
	while (first->index != 0)
	{
		if (i < 2)
			ra(stack);
		else
			rra(stack);
		first = stack->a;
	}
	push_4_nodes(stack, first);
}
