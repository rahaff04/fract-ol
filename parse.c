/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:27:05 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/12 15:07:02 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_number(char *str)
{
	int	i;
	int	dot_count;
	int	digit_count;

	i = 0;
	dot_count = 0;
	digit_count = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		else if (str[i] >= '0' && str[i] <= '9')
			digit_count++;
		else
			return (0);
		if (dot_count > 1)
			return (0);
		i++;
	}
	return (digit_count > 0);
}


static int	parse_julia(t_fractal *f, int ac, char **av)
{
	if (ac != 4)
	{
		write(2, "./fractol julia <real> <imaginary>\n", 34);
		return (1);
	}
	if (!is_valid_number(av[2]) || !is_valid_number(av[3]))
	{
		write(2, "Error: Invalid number format\n", 28);
		return (1);
	}
	f->julia_cr = ft_atof(av[2]);
	f->julia_ci = ft_atof(av[3]);
	if (f->julia_cr < -2.0 || f->julia_cr > 2.0
		|| f->julia_ci < -2.0 || f->julia_ci > 2.0)
	{
		write(2, "Error: Julia parameters should be between [-2.0, 2.0]\n", 53);
		return (1);
	}
	return (0);
}

int	parsing(t_fractal *f, int ac, char **av)
{
	if (ac < 2)
	{
		write(2, "./fractol <fractal_name> [julia_parameters]\n", 43);
		return (1);
	}
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0 && ac == 2)
	{
		f->type = MANDELBROT;
		return (0);
	}
	else if (ft_strncmp(av[1], "julia", 6) == 0)
	{
		f->type = JULIA;
		return (parse_julia(f, ac, av));
	}
	else
	{
		write(2, "Error: Unknown fractal name.\n", 28);
		return (1);
	}
}
