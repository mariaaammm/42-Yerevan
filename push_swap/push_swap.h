/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:22:56 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/10/05 17:59:39 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_list {
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_data {
	t_list	*a;
	t_list	*b;
}	t_data;

long long int	ft_atoi(char *str);
int				is_letter(char **str);
int				repeated(char	**str);
int				out_of_range(char	**str);
void			handling(char **x);

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
int				sorted_initially(t_list *stack);
size_t			word_count(char const *s, char c);
char			*putword(const char *s, size_t startIndex, size_t len);
char			**ft_split(char *s, char c);

void			sa(t_data *stack);
void			sb(t_data *stack);
void			ss(t_data *stack);
void			pa(t_data *stack);
void			pb(t_data *stack);
void			ra(t_data *stack);
void			rb(t_data *stack);
void			rr(t_data *stack);
void			rra(t_data *stack);
void			rrb(t_data *stack);
void			rrr(t_data *stack);

int				list_size(t_list *list);
int				find_max(t_data *stack);
int				above_or_below(t_data *stack);
void			loop(t_data *stack, t_list *first, t_list *min);
void			indexing(t_data *stack);

void			push_swap(t_data *stack);
void			butterfly_a_to_b(t_data *stack);
int				counter_count(int size);
void			butterfly_b_to_a(t_data *stack);
void			do_b_to_a(int i, int size, t_data *stack, t_list *b);

void			sort_two(t_data *stack);
void			three_nodes(t_data *stack);
void			four_nodes(t_data *stack, int n);
void			five_nodes(t_data *stack);
void			push_3_nodes(t_data *stack, t_list *node);
void			push_4_nodes(t_data *stack, t_list *node);
void			push_5_nodes(t_data *stack, t_list *node);

char			**get_list(char **av);
t_list			*get_a_stack(char **str);
t_list			*get_b_stack(void);
void			free_stack(t_list *stack);

#endif
