/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:26:38 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/12 14:59:53 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 600
# define MOVE_STEP 0.2

typedef enum e_type
{
	MANDELBROT,
	JULIA,
}	t_type;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	zoom;
	int		max_iter;
	t_type	type;
	double	julia_cr;
	double	julia_ci;
}	t_fractal;

void			ft_bzero(void *s, size_t n);
int				ft_strncmp(char *s1, char *s2, size_t n);
double			ft_atof(char *str);
int				create_img(t_fractal *f);
void			pixel(t_fractal *f, int x, int y, int color);
int				get_color(int i, int max_iter);
void			draw_mandelbrot(t_fractal *f);
int				mouse_zoom_ma(int button, int x, int y, t_fractal *f);
int				key_hook_up_down_ma(int keycode, t_fractal *f);
int				key_hook_left_right_ma(int keycode, t_fractal *f);
int				key_event_ma(int keycode, t_fractal *f);
int				mouse_zoom_ju(int button, int x, int y, t_fractal *f);
int				key_hook_up_down_ju(int keycode, t_fractal *f);
int				key_hook_left_right_ju(int keycode, t_fractal *f);
int				key_event_ju(int keycode, t_fractal *f);
void			draw_julia(t_fractal *f);
int				close_window(t_fractal *f);
int				parsing(t_fractal *f, int ac, char **av);
void			declare_mvaribles(t_fractal *f);
void			declare_jvaribles(t_fractal *f);
void			init_mandel(t_fractal *f);
void			init_julia(t_fractal *f);
int				init_fractal(t_fractal *f);

#endif