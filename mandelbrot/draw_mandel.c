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

int	mandelbrot(double cr, double ci)
{
	double	zr;
	double	zi;
	double	temp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		if (zr * zr + zi * zi > 4)
			break ;
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

static int	calc_mandel(t_calc_data *data, int x, int y)
{
	double	cr;
	double	ci;

	cr = data->f->min_re + x * data->re_factor;
	ci = data->f->max_im - y * data->im_factor;
	return (mandelbrot(cr, ci));
}

static void	draw_mandel_row(t_fractal *f, int y,
				double re_factor, double im_factor)
{
	int				x;
	int				i;
	double			ci;
	t_calc_data		data;

	data.f = f;
	data.re_factor = re_factor;
	data.im_factor = im_factor;
	ci = f->max_im - y * im_factor;
	x = 0;
	while (x < WIDTH)
	{
		i = calc_mandel(&data, x, y);
		pixel(f, x, y, get_color(i));
		x++;
	}
}

void	draw_mandelbrot(t_fractal *f)
{
	int		y;
	double	re_factor;
	double	im_factor;

	re_factor = (f->max_re - f->min_re) / WIDTH;
	im_factor = (f->max_im - f->min_im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		draw_mandel_row(f, y, re_factor, im_factor);
		y++;
	}
}
