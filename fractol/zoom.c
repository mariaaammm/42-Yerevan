/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:06:57 by mpetrosy          #+#    #+#             */
/*   Updated: 2022/11/08 13:27:25 by mpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(double x, double y, t_fractol *f)
{
	f->r = (x / f->zoom + f->r - x / (f->zoom * 1.25));
	f->i = (y / f->zoom + f->i - y / (f->zoom * 1.25));
	f->zoom *= 1.25;
}

void	zoom_out(double x, double y, t_fractol *f)
{
	f->r = x / f->zoom + f->r - x / (f->zoom / 1.25);
	f->i = y / f->zoom + f->i - y / (f->zoom / 1.25);
	f->zoom /= 1.25;
}
