/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:27:35 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/09/29 17:35:05 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *stack)
{
	t_list	*one;
	t_list	*two;

	write(1, "sa\n", 3);
	if (stack->a == NULL && stack->a->next == NULL)
		return ;
	one = stack->a;
	two = stack->a->next;
	one->next = two->next;
	two->next = one;
	stack->a = two;
}

void	sb(t_data *stack)
{
	t_list	*one;
	t_list	*two;

	write(1, "sb\n", 3);
	if (stack->b == NULL && stack->b->next == NULL)
		return ;
	one = stack->b;
	two = stack->b -> next;
	one->next = two->next;
	two->next = one;
	stack->b = two;
}

void	ss(t_data *stack)
{
	write(1, "ss", 2);
	sa(stack);
	sb(stack);
}

void	pa(t_data	*stack)
{
	t_list	*a;
	t_list	*b;

	write(1, "pa\n", 3);
	if (stack->b == NULL)
		return ;
	a = stack->a;
	b = stack->b;
	stack->b = stack->b->next;
	b->next = a;
	stack->a = b;
}

void	pb(t_data *stack)
{
	t_list	*a;
	t_list	*b;

	write(1, "pb\n", 3);
	if (stack->a == NULL)
		return ;
	a = stack->a;
	b = stack->b;
	stack->a = stack->a->next;
	a->next = b;
	stack->b = a;
}
