/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:26:13 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/21 15:45:31 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	f;

	ft_bzero(&f, sizeof(t_fractal));
	if (parsing(&f, argc, argv) != 0)
		return (1);
	if (init_fractal(&f) != 0)
	{
		write(2, "Error initializing fractal\n", 27);
		return (1);
	}
	mlx_loop(f.mlx);
	return (0);
}
