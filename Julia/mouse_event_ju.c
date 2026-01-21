/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_ju.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:29:44 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/21 14:23:41 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_zoom_ju(int button, int x, int y, t_fractal *f)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;
	int		saved;

	if (button == 4)
		zoom_factor = 0.8;
	else if (button == 5)
		zoom_factor = 1.25;
	else
		return (0);
	mouse_re = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
	mouse_im = f->max_im - y * (f->max_im - f->min_im) / HEIGHT;
	f->min_re = mouse_re + (f->min_re - mouse_re) * zoom_factor;
	f->max_re = mouse_re + (f->max_re - mouse_re) * zoom_factor;
	f->min_im = mouse_im + (f->min_im - mouse_im) * zoom_factor;
	f->max_im = mouse_im + (f->max_im - mouse_im) * zoom_factor;
	saved = f->max_iter;
	f->max_iter = 60;
	draw_julia(f);
	f->max_iter = saved;
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
