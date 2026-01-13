/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:45:48 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/12 14:32:20 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	mandelbrot(double cr, double ci)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		if (zr * zr + zi * zi > 4)
			break ;
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

static void	draw_row(t_fractal *f, int y, double re_f, double im_f)
{
	int		x;
	double	cr;
	double	ci;

	x = 0;
	ci = f->max_im - y * im_f;
	while (x < WIDTH)
	{
		cr = f->min_re + x * re_f;
		pixel(f, x, y, get_color(mandelbrot(cr, ci)));
		x++;
	}
}

void	draw_mandelbrot(t_fractal *f)
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

