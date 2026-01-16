/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:29:20 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/12 12:07:06 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	julia(double zr, double zi, t_fractal *f)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < f->max_iter)
	{
		if (zr * zr + zi * zi > 4)
			break ;
		tmp = zr * zr - zi * zi + f->julia_cr;
		zi = 2 * zr * zi + f->julia_ci;
		zr = tmp;
		i++;
	}
	return (i);
}

static void	draw_row(t_fractal *f, int y, double re_f, double im_f)
{
	int			x;
	double	zr;
	double	zi;

	x = 0;
	zi = f->max_im - y * im_f;
	while (x < WIDTH)
	{
		zr = f->min_re + x * re_f;
		pixel(f, x, y, get_color(julia(zr, zi, f), f->max_iter));
		x++;
	}
}

void	draw_julia(t_fractal *f)
{
	int		y;
	double	re_f;
	double	im_f;

	re_f = (f->max_re - f->min_re) / WIDTH;
	im_f = (f->max_im - f->min_im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		draw_row(f, y, re_f, im_f);
		y++;
	}
}
