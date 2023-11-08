/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:40:56 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/04/26 16:36:58 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_putnbr(int n);
int	ft_base(unsigned long long num, unsigned int base, int type);
int	ft_ptr(unsigned long long ptr);
int	ft_printf(const char *form, ...);
int	create_form(const char *form, va_list *args);

#endif
