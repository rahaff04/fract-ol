#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 800
#define HEIGHT 800
typedef struct s_img
{
	void	*imgptr;
	char	*pixils; 
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	char		*name;
	void	*mlx_con; //mlx init()
	void 	*mlx_win; //mlx_new_window()
	t_img	*img;     //mlx_new_image()
}	t_fractol;

int	ft_strncmp(char *s1, char *s2, size_t n);
void	init_fractol(t_fractol *f);

#endif