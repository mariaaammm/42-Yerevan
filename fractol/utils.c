/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:03:11 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/11/06 16:46:02 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atoi(const char *str, t_fractol *f)
{
	if (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				f->min = -1;
			str++;
		}
		while (*str && *str >= 48 && *str <= 57)
		{
			f->res = f->res * 10 + (*str - '0');
			str++;
		}
		if ((*str < 48 || *str > 57) && *str)
		{
			f->atoi_flag = 2;
			return (0);
		}
	}
	return ((double)(f->res * f->min));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	map_real_part(double x, double width, double min_r, double max_r)
{
	double	range;

	range = max_r - min_r;
	return (x * (range / width) + min_r);
}

double	map_img_part(double y, double height, double min_i, double max_i)
{
	return (y * ((max_i - min_i) / height) + min_i);
}

void	handle(void)
{
	write(1, "Choose a fractal name - Mandelbrot | Julia", 42);
	exit(0);
}
