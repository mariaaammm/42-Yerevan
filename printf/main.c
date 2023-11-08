/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:32:29 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/05/04 19:05:34 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	
	char a = 'v';
    printf("%c\n", a);
    ft_printf("%c\n", a);

    char b[] = "Hello dear friend";
    printf("%s\n", b);
    ft_printf("%s\n", b);

    int c = 454;
	printf("%d\n", c);
	ft_printf("%d\n", c);
	printf("%i\n", c);
	ft_printf("%i\n", c);
    printf("%u\n", c);
    ft_printf("%u\n", c);

    int d = 125;
    printf("%x\n", d);
    ft_printf("%x\n", d);

    int e = 362;
    printf("%X\n", e);
    ft_printf("%X\n", e);

    printf("%p\n", &e);
    ft_printf("%p\n", &e);

    printf("%%\n");
    ft_printf("%%\n");

	printf("Hello  %c world %c", a, a);
	ft_printf("Hello %c world %c", a, a);
}
