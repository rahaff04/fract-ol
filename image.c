/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:26:23 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/12 12:16:19 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_img(t_fractal *f)
{
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		return (1);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);
	if (!f->addr)
	{
		return (1);
	}
	return (0);
}

int	get_color(int i, int max_iter)
{
	int	r;
	int	g;
	int	b;

	if (i == max_iter)
		return (0x000000);
	r = (i * 9) % 256;
	g = (i * 7) % 256;
	b = (i * 5) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	pixel(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = f->addr + (y * f->line_length + x * (f->bpp / 8));
	*(unsigned int *) dst = color;
}
