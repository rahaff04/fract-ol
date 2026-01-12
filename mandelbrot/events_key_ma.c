/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key_ma.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:28:43 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/12 12:01:12 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hook_up_down_ma(int keycode, t_fractal *f)
{
	double	move;

	move = MOVE_STEP * (f->max_re - f->min_re);
	if (keycode == 65362)
	{
		f->min_im += move;
		f->max_im += move;
	}
	else if (keycode == 65364)
	{
		f->min_im -= move;
		f->max_im -= move;
	}
	draw_mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	key_hook_left_right_ma(int keycode, t_fractal *f)
{
	double	move;

	move = MOVE_STEP * (f->max_re - f->min_re);
	if (keycode == 65361)
	{
		f->min_re -= move;
		f->max_re -= move;
	}
	else if (keycode == 65363)
	{
		f->min_re += move;
		f->max_re += move;
	}
	draw_mandelbrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

int	key_event_ma(int keycode, t_fractal *f)
{
	if (keycode == 65307)
		close_window(f);
	else if (keycode == 65362 || keycode == 65364)
		key_hook_up_down_ma(keycode, f);
	else if (keycode == 65361 || keycode == 65363)
		key_hook_left_right_ma(keycode, f);
	return (0);
}
