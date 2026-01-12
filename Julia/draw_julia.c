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

static int	calc_julia(t_calc_data *data, double zr, double zi)
{
	double	temp;
	int		i;

	i = 0;
	while (i < MAX_ITER)
	{
		if (zr * zr + zi * zi > 4)
			break ;
		temp = zr * zr - zi * zi + data->f->julia_cr;
		zi = 2 * zr * zi + data->f->julia_ci;
		zr = temp;
		i++;
	}
	return (i);
}

static void	draw_julia_row(t_fractal *f, int y,
		double re_factor, double im_factor)
{
	int				x;
	int				i;
	double			zr;
	double			zi;
	t_calc_data		data;

	data.f = f;
	data.re_factor = re_factor;
	data.im_factor = im_factor;
	zi = f->max_im - y * im_factor;
	x = 0;
	while (x < WIDTH)
	{
		zr = f->min_re + x * re_factor;
		i = calc_julia(&data, zr, zi);
		pixel(f, x, y, get_color(i));
		x++;
	}
}

void	draw_julia(t_fractal *f)
{
	int		y;
	double	re_factor;
	double	im_factor;

	re_factor = (f->max_re - f->min_re) / WIDTH;
	im_factor = (f->max_im - f->min_im) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		draw_julia_row(f, y, re_factor, im_factor);
		y++;
	}
}
