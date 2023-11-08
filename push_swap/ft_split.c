/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:50:08 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/09/29 17:21:52 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	letter_count(char *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;

	i = 0;
	count = 1;
	len = ft_strlen(s) - 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[len] && s[len] == c && i < len)
		len--;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < len)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

char	*create_word(char *s, size_t start_index, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[start_index + i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	quantity;
	char	**result;

	start = 0;
	i = 0;
	quantity = letter_count(s, c);
	result = malloc(sizeof(char *) * (quantity + 1));
	if (!s || !result)
		return (NULL);
	while (i < quantity)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		result[i++] = create_word(s, start, end - start);
		start = end;
	}
	result[i] = NULL;
	free(s);
	return (result);
}
