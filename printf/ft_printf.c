/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:12:55 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/26 16:31:04 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, form);
	while (*form != '\0')
	{
		if (*form == '%' && form++)
		{
			if (*form == 'c' || *form == 's'
				|| *form == 'd' || *form == 'i' || *form == 'u'
				|| *form == 'x' || *form == 'X'
				|| *form == 'p' || *form == '%')
				i += create_form(form, &args);
		}
		else
			i += ft_printchar(*form);
		form++;
		va_end(args);
	}
	return (i);
}
