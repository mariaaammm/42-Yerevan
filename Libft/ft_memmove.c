/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:27:57 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/03/21 16:16:38 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	unsigned const char	*src2;

	dst2 = dst;
	src2 = src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*(dst2 + len) = *(src2 + len);
	}
	return (dst);
}
