#include "fractol.h"

int     mandelbrot(double cr, double ci)
{
    double zr;
    double zi;
    double temp;
    int i;

    zr = 0;
    zi = 0;
    i = 0;
    while (zi * zi + zr * zr <= 4 && i < MAX_ITER)
    {
        temp = zr * zr - zi * zi + cr;
        zi = 2 * zr * zi + ci;
        zr = temp;
        if (zr * zr + zi * zi > 4)
            break ;
        i++;
    }
    return (i);
}
void    draw_mandelbrot(t_fractal *f)
{
    int x;
    int y;
    double cr;
    double ci;
    int i;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            cr = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
            ci = f->max_im - y * (f->max_im - f->min_im) / HEIGHT;
            i = mandelbrot(cr, ci);
            pixel(f, x, y, i * 0x050505 / MAX_ITER);
            x++;
        }
        y++;
    }
}