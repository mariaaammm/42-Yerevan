/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rev_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:51:20 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/09/29 17:33:11 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *stack)
{
	t_list	*one;
	t_list	*two;

	write(1, "ra\n", 3);
	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	one = stack->a;
	two = stack->a->next;
	while (stack->a->next)
		stack->a = stack->a->next;
	stack->a->next = one;
	stack->a = two;
	one->next = NULL;
}

void	rb(t_data *stack)
{
	t_list	*one;
	t_list	*two;

	write(1, "rb\n", 3);
	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	one = stack->b;
	two = stack->b->next;
	while (stack->b->next)
		stack->b = stack->b->next;
	stack->b->next = one;
	stack->b = two;
	one->next = NULL;
}

void	rr(t_data *stack)
{
	write(1, "rr", 2);
	ra(stack);
	rb(stack);
}

void	rra(t_data *stack)
{
	t_list	*first;
	t_list	*before;
	t_list	*last;

	write(1, "rra\n", 4);
	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	first = stack->a;
	while (stack->a->next->next != NULL)
		stack->a = stack->a->next;
	before = stack->a;
	last = stack->a->next;
	last->next = first;
	before->next = NULL;
	first = last;
	stack->a = last;
}

void	rrb(t_data *stack)
{
	t_list	*first;
	t_list	*before;
	t_list	*last;

	write(1, "rrb\n", 4);
	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	first = stack->b;
	while (stack->b->next->next != NULL)
		stack->b = stack->b->next;
	before = stack->b;
	last = stack->b->next;
	last->next = first;
	before->next = NULL;
	first = last;
	stack->b = last;
}
