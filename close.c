#include "fractol.h"

int close_window(t_fractal *f)
{
    mlx_destroy_image(f->mlx, f->img);
    mlx_destroy_window(f->mlx, f->win);
    mlx_destroy_display(f->mlx);
    free(f->mlx);
    exit(0);
    return (0);
}