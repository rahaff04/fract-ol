#include "../fractol.h"

int    julia(double zr, double zi, t_fractal *f)
{
    double temp;
    int i = 0;

    while (zr * zr + zi * zi <= 4 && i < MAX_ITER)
    {
        temp = zr * zr - zi * zi + f->julia_cr;
        zi = 2 * zr * zi + f->julia_ci;
        zr = temp;
        i++;
    }
    return (i);
}

void    draw_julia(t_fractal *f)
{
    int x;
    int y;
    double zr;
    double zi;
    int i;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            zr = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
            zi = f->max_im - y * (f->max_im - f->min_im) / HEIGHT;
            i = julia(zr, zi, f);
            pixel(f, x, y, get_color(i));
            x++;
        }
        y++;
    }
}