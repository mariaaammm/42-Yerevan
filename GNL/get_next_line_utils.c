/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:13:52 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/13 16:54:32 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s && s[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s && s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)(s + i));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	if (s1 != NULL)
		free(s1);
	str[i] = 0;
	return (str);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dst;

	i = ft_strlen(s1);
	dst = malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = 0;
	if (!dst || !s1)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	size;
	size_t	l;

	if (!s || !*s)
		return (NULL);
	size = ft_strlen(s);
	if (len == 0 || start > size)
		l = 0;
	else if (size - start > size)
		l = len;
	else
		l = size - start;
	sub = malloc((l + 1) * sizeof(char));
	i = 0;
	if (!sub)
		return (NULL);
	while (s && s[i] && len && size > start)
	{
		sub[i++] = s[start++];
		len--;
	}
	sub[i] = '\0';
	return (sub);
}
