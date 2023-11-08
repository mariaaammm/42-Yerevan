/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:51:20 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/10/05 17:53:42 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *stack)
{
	if (list_size(stack->a) == 1 || sorted_initially(stack->a) == 1)
		return ;
	else if (list_size(stack->a) == 2)
		sort_two(stack);
	else if (list_size(stack->a) == 3)
		three_nodes(stack);
	else if (list_size(stack->a) == 4)
		four_nodes(stack, 0);
	else if (list_size(stack->a) == 5)
		five_nodes(stack);
	else
	{
		butterfly_a_to_b(stack);
		butterfly_b_to_a(stack);
	}
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int	main(int ac, char **av)
{
	char	**args;
	t_data	stack;

	if (ac > 1)
	{
		args = get_list(av);
		handling(args);
		stack.a = get_a_stack(args);
		stack.b = get_b_stack();
		indexing(&stack);
		push_swap(&stack);
		free_stack(stack.a);
	}
	return (0);
}
