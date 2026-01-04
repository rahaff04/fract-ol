#include "fractol.h"

int close_window(t_fractal *f)
{
    if (f->img)
        mlx_destroy_image(f->mlx, f->img);
    if (f->win)
        mlx_destroy_window(f->mlx, f->win);
    if (f->mlx)
    {
        mlx_destroy_display(f->mlx);
        free(f->mlx);
    }
    exit(0);
}