/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:54:35 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/11/06 16:45:13 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	values(t_fractol *f)
{
	f->zoom = 150;
	f->line = 0;
	f->column = 0;
	f->r = -2.05;
	f->i = -1.3;
	f->maxiter = 250;
	f->width = 900;
	f->height = 900;
	f->color = 25525414;
	f->jr = 1;
	f->ji = 1;
	f->n = 0;
	f->ptr = 5;
	f->atoi_flag = 3;
	f->res = 0;
	f->min = 1;
}

void	init_get(double width, double height, t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "fract'ol");
	data->img = mlx_new_image(data->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->endian);
}

void	exec_mlx(t_fractol *f, t_data *data)
{
	mlx_hook(data->win, 17, 0, &destroy, data);
	mlx_key_hook(data->win, &key_hook, f);
	mlx_mouse_hook(data->win, &mouse_hook, f);
	mlx_loop(data->mlx);
}

void	which_fractal(char **av, t_fractol *f, t_data *data)
{
	if (ft_atoi(av[2], f) >= 0)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
		{
			f->ptr = 3;
			draw_mandelbrot(f, f->data);
		}
		else if (ft_strcmp(av[1], "Julia") == 0)
		{
			f->ptr = 1;
			mlx_hook(data->win, 6, 1L << 6, &animation, f);
			draw_julia(f, f->data);
		}
		else if (ft_strcmp(av[1], "bonus") == 0)
		{
			f->ptr = 2;
			draw_bonus(f, f->data);
		}
	}
}

int	main(int ac, char **av)
{
	t_fractol	*f;
	t_data		*data;

	if (ac != 3)
		handle();
	else
	{
		f = malloc(sizeof(t_fractol));
		data = malloc(sizeof(t_data));
		values(f);
		init_get(f->width, f->height, data);
		f->data = data;
		f->n = ft_atoi(av[2], f);
		if (f->atoi_flag == 2)
			handle();
		which_fractal(av, f, data);
		if (f->ptr == 5)
			handle();
		exec_mlx(f, f->data);
	}
	return (0);
}
