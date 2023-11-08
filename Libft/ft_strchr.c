/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:08:30 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/03/28 20:41:29 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	x;

	if (!c)
		return ((char *)s + ft_strlen(s));
	x = c;
	while (*s)
	{
		if (*s == x)
			return ((char *)s);
		else if (!*s++)
			return (0);
	}
	return (0);
}
