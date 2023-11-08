/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:00:28 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/11/06 16:43:36 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(int keycode, t_fractol *f)
{
	if (keycode == 0)
		f->color = 3823985;
	else if (keycode == 1)
		f->color = 3879239;
	else if (keycode == 2)
		f->color = 18523938;
	else if (keycode == 13)
		f->color = 232202250;
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 53)
	{
		mlx_destroy_window(f->data->mlx, f->data->win);
		exit(1);
	}
	color(keycode, f);
	if (keycode == 123)
		f->r -= 30 / f->zoom;
	else if (keycode == 124)
		f->r += 30 / f->zoom;
	else if (keycode == 125)
		f->i += 30 / f->zoom;
	if (keycode == 126)
		f->i -= 30 / f->zoom;
	if (f->ptr == 3)
		draw_mandelbrot(f, f->data);
	else if (f->ptr == 1)
		draw_julia(f, f->data);
	else if (f->ptr == 2)
		draw_bonus(f, f->data);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	if (mousecode == 5)
		zoom_in(x, y, f);
	else if (mousecode == 4)
		zoom_out(x, y, f);
	if (f->ptr == 3)
		draw_mandelbrot(f, f->data);
	else if (f->ptr == 1)
		draw_julia(f, f->data);
	else if (f->ptr == 2)
		draw_bonus(f, f->data);
	return (0);
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
