/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events_ma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:28:51 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/12 12:00:15 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h" 

int mouse_zoom_ma(int button, int x, int y, t_fractal *f) 
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
	ft_bzero(f->addr, HEIGHT * f->line_length);
	saved = f->max_iter;
	f->max_iter = 60;
	draw_mandelbrot(f);
	f->max_iter = saved; 
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0); 
	return (0); 
}

