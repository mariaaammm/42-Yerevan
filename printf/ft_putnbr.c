/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:01:47 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/26 16:32:01 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	num;
	int				i;

	i = 0;
	if (n < 0)
	{
		i += ft_printchar('-');
		num = n * (-1);
	}
	else
		num = n;
	if (num >= 10)
		i += ft_putnbr(num / 10);
		i += ft_printchar(num % 10 + '0');
	return (i);
}
