/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:54:28 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/11/08 14:54:37 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
int	bonus_is_in_set(t_fractol *f)
{
	int		iter;
	double	cx;
	double	cy;

	iter = -1;
	f->cr = f->line / f->zoom + f->r;
	f->ci = f->column / f->zoom + f->i;
	while (++iter < f->maxiter && f->cr * f->cr + f->ci * f->ci < 4)
	{
		cx = f->cr * f->cr - f->ci * f->ci - 0.8;
		cy = 2 * fabs(f->cr * f->ci) - f->ci * f->cr - 0.7;
		f->cr = cx + f->r;
		f->ci = cy + f->i;
	}
	return (iter);
}
*/
/*
int	bonus_is_in_set(t_fractol *f)
{
	int		iter;
	double	cx;
	double	cy;

	iter = -1;
	f->cr = f->line / f->zoom + f->r;
	f->ci = f->column / f->zoom + f->i;
	while (++iter < f->maxiter && f->cr * f->cr + f->ci * f->ci < 4)
	{
		cx = fabs(f->cr * f->cr - f->ci * f->ci);
		cy =  2 * f->cr * f->ci;
		f->cr = cx + f->r;
		f->ci = cy + f->i;
	}
	return (iter);
}
*/

/*
int	bonus_is_in_set(t_fractol *f)
{
	int		iter;
	double	cx;
	double	cy;

	iter = -1;
	f->cr = f->line / f->zoom + f->r;
	f->ci = f->column / f->zoom + f->i;
	while (++iter < f->maxiter && f->cr * f->cr + f->ci * f->ci < 4)
	{
		cx = f->cr * f->cr - f->ci * f->ci;
		cy = exp(2 * f->cr * f->ci);
		f->cr = cx + f->r;
		f->ci = cy + f->i;
	}
	return (iter);
}
*/
/*
int	bonus_is_in_set(t_fractol *f)
{
	int		iter;
	double	cx;
	double	cy;

	iter = -1;
	f->cr = f->line / f->zoom + f->r;
	f->ci = f->column / f->zoom + f->i;
	while (++iter < f->maxiter && f->cr * f->cr + f->ci * f->ci < 4)
	{
		cx = f->cr * f->cr + f->ci * f->ci;
		cy = exp(2 * f->cr);
		f->cr = cx + f->r;
		f->ci = cy + f->i;
	}
	return (iter);
}*/
/*
int	bonus_is_in_set(t_fractol *f)
{
	int		iter;
	double	cx;
	double	cy;

	iter = -1;
	f->cr = f->line / f->zoom + f->r;
	f->ci = f->column / f->zoom + f->i;
	while (++iter < f->maxiter && f->cr * f->cr + f->ci * f->ci < 4)
	{
		cx = f->cr * f->cr + f->ci * f->ci;
		cy = exp(2 * f->cr * f->ci);
		f->cr = cx + f->r;
		f->ci = cy + f->i;
	}
	return (iter);
}
*/

int	bonus_is_in_set(t_fractol *f)
{
	int		iter;
	double	cx;
	double	cy;

	iter = -1;
	f->cr = f->line / f->zoom + f->r;
	f->ci = f->column / f->zoom + f->i;
	while (++iter < f->maxiter && f->cr * f->cr + f->ci * f->ci < 4)
	{
		cx = f->cr * f->cr * f->cr - 3 * f->cr * f->ci * f->ci;
		cy = 3 * f->cr * f->cr * f->ci - f->ci * f->ci * f->ci;
		f->cr = cx + f->r;
		f->ci = cy + f->i;
	}
	return (iter);
}

void	draw_bonus(t_fractol *f, t_data *data)
{
	f->line = -1;
	while (++f->line < f->width)
	{
		f->column = -1;
		while (++f->column < f->height)
		{			f->t = bonus_is_in_set(f);
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
