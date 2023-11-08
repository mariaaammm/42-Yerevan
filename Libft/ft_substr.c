/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:24:05 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/01 18:15:46 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*sub;

	i = 0;
	if (ft_strlen(s) < start)
	{
		sub = malloc(sizeof(char));
		sub[0] = '\0';
		return (sub);
	}
	l = ft_strlen(s + start);
	if (l < len)
		len = l;
	sub = (char *) malloc(len);
	if (!sub)
		return (0);
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
