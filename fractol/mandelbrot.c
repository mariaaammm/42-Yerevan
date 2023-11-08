/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:55:25 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/11/09 12:20:31 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_is_in_set(t_fractol *f)
{
	int		iter;
	double	cx;
	double	cy;
	double	cr0;
	double	ci0;

	iter = -1;
	f->cr = f->line / f->zoom + f->r;
	f->ci = f->column / f->zoom + f->i;
	cr0 = f->cr;
	ci0 = f->ci;
	while (++iter < f->maxiter && f->cr * f->cr
		+ f->ci * f->ci < 4)
	{
		cx = f->cr * f->cr - f->ci * f->ci;
		cy = 2 * f->cr * f->ci;
		f->cr = cx + cr0;
		f->ci = cy + ci0;
	}
	return (iter);
}

void	my_mlx_pixel_put(t_data *data, double x, double y, int color)
{
	char	*dst;

	dst = data->addr + (int)(y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	write_str(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 10, 0, 0xFFFFFF,
		"Use arrow keys to move");
	mlx_string_put(data->mlx, data->win, 10, 25, 0xFFFFFF,
		"Change colors with A, S, D, E");
	mlx_string_put(data->mlx, data->win, 10, 50, 0xFFFFFF,
		"Scroll for zooming in / zooming out");
}

double	coloring(t_fractol *f)
{
	double	a;
	double	b;
	double	res;

	b = pow(((double)f->t / (double)f->maxiter), 4);
	res = pow(b * f->n, 2) / sqrt(b * f->n);
	a = fmod(res, f->n);
	return (a);
}

void	draw_mandelbrot(t_fractol *f, t_data *data)
{
	f->line = -1;
	while (++f->line < f->width)
	{
		f->column = -1;
		while (++f->column < f->height)
		{
			f->t = mandelbrot_is_in_set(f);
			if (f->t == f->maxiter)
				my_mlx_pixel_put(data, f->line, f->column, 0x000000);
			else
				my_mlx_pixel_put(data, f->line, f->column,
					f->color * coloring(f));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	write_str(data);
}
