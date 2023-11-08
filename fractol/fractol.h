/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:51:38 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/11/06 16:52:52 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define A 0
# define S 1
# define W 13
# define D 2

typedef struct data
{
	void	*mlx;
	void	*win;
	char	*addr;
	void	*img;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractol
{
	int				bpp;
	double			jr;
	double			ji;
	double			cr;
	double			ci;
	double			zoom;
	double			r;
	double			i;
	int				line;
	int				column;
	int				x;
	int				t;
	int				n;
	int				color;
	int				fract;
	int				ptr;
	int				atoi_flag;
	unsigned int	res;
	int				min;
	int				width;
	int				height;
	int				maxiter;
	t_data			*data;
}					t_fractol;

int		mandelbrot_is_in_set(t_fractol *f);
void	my_mlx_pixel_put(t_data *data, double x, double y, int color);
void	draw_mandelbrot(t_fractol *f, t_data *data);
void	write_str(t_data *data);
int		julia(t_fractol *f);
void	draw_julia(t_fractol *f, t_data *data);
int		animation(int w, int h, t_fractol *f);
void	color(int keycode, t_fractol *f);
int		mouse_hook(int mousecode, int w, int h, t_fractol *f);
void	color(int keycode, t_fractol *f);
int		key_hook(int keycode, t_fractol *f);
int		ft_strcmp(char *s1, char *s2);
double	map_real_part(double x, double width, double min_r, double max_r);
double	map_img_part(double y, double height, double min_i, double max_i);
void	zoom_in(double x, double y, t_fractol *f);
void	zoom_out(double x, double y, t_fractol *f);
void	init_get(double width, double height, t_data *data);
int		destroy(t_data *data);
void	exec_mlx(t_fractol *f, t_data *data);
void	values(t_fractol *f);
int		main(int ac, char **av);
double	coloring(t_fractol *f);
void	handle(void);
double	ft_atoi(const char *str, t_fractol *coord);
int		bonus_is_in_set(t_fractol *f);
void	draw_bonus(t_fractol *f, t_data *data);

#endif
