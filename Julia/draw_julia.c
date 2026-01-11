#include "../fractol.h"

int    julia(double zr, double zi, t_fractal *f)
{
    double temp;
    int i;

    i = 0;
    while (i < MAX_ITER)
    {
        if (zr * zr + zi * zi > 4)
            break ;
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
    double re_factor;
    double im_factor;

    re_factor = (f->max_re - f->min_re) / WIDTH;
    im_factor = (f->max_im - f->min_im) / HEIGHT;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        zi = f->max_im - y * im_factor;
        while (x < WIDTH)
        {
            zr = f->min_re + x * re_factor;
            i = julia(zr, zi, f);
            pixel(f, x, y, get_color(i));
            x++;
        }
        y++;
    }
}