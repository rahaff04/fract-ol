#include "fractol.h"

void create_img(t_fractal *f)
{
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    if (!f->img)
        exit(1);
    f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);
    if (!f->addr)
        exit(1);
}

void pixel(t_fractal *f, int x, int y, int color)
{
    char    *dst;

    dst = f->addr + (y * f->line_length + x * (f->bpp / 8));
    *(unsigned int*)dst = color;
}