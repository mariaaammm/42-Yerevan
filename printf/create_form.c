/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_form.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:41:15 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/26 14:50:09 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	create_form(const char *form, va_list *args)
{
	int	i;

	i = 0;
	if (*form == 'c')
		i += ft_printchar(va_arg(*args, int));
	else if (*form == 's')
		i += ft_printstr(va_arg(*args, char *));
	else if (*form == 'p')
		i += ft_ptr(va_arg(*args, unsigned long long));
	else if (*form == 'i' || *form == 'd')
		i += ft_putnbr(va_arg(*args, int));
	else if (*form == 'u')
		i += ft_base(va_arg(*args, unsigned int), 10, 87);
	else if (*form == 'X')
		i += ft_base(va_arg(*args, unsigned int), 16, 55);
	else if (*form == 'x')
		i += ft_base(va_arg(*args, unsigned int), 16, 87);
	else if (*form == '%')
		i += ft_printchar('%');
	return (i);
}
