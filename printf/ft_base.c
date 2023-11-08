/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:42:38 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/26 15:13:21 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base(unsigned long long num, unsigned int base, int type)
{
	int	i;

	i = 0;
	if (num > base - 1)
		i += ft_base(num / base, base, type);
	if (num % base < 10)
		i += ft_printchar(num % base + 48);
	else if (num % base >= 10 && type == 87)
		i += ft_printchar(num % base + 87);
	else if (num % base >= 10 && type == 55)
		i += ft_printchar(num % base + 55);
	return (i);
}
