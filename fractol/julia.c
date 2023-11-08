/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:30:30 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/11/06 16:43:12 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_is_in_set(t_fractol *f)
{
	int		iter;
	double	cx;
	double	cy;

	iter = -1;
	f->cr = f->line / f->zoom + f->r;
	f->ci = f->column / f->zoom + f->i;
	while (++iter < f->maxiter && f->cr * f->cr
		+ f->ci * f->ci < 4)
	{
		cx = f->cr * f->cr - f->ci * f->ci;
		cy = 2 * f->cr * f->ci;
		f->cr = cx + f->jr;
		f->ci = cy + f->ji;
	}
	return (iter);
}

void	draw_julia(t_fractol *f, t_data *data)
{
	f->line = -1;
	while (++f->line < f->width)
	{
		f->column = -1;
		while (++f->column < f->height)
		{
			f->t = julia_is_in_set(f);
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

int	animation(int x, int y, t_fractol *f)
{
	f->jr = map_real_part((double)x, f->width, -2, 2);
	f->ji = map_img_part((double)y, f->height, -2, 2);
	draw_julia(f, f->data);
	return (0);
}
