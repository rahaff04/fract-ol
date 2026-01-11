#include "../fractol.h"

int     mandelbrot(double cr, double ci)
{
    double zr;
    double zi;
    double temp;
    int i;

    zr = 0;
    zi = 0;
    i = 0;
    while (i < MAX_ITER)
    {
        if (zr * zr + zi * zi > 4)
            break;
        temp = zr * zr - zi * zi + cr;
        zi = 2 * zr * zi + ci;
        zr = temp;
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
    double re_factor;
    double im_factor;

    re_factor = (f->max_re - f->min_re) / WIDTH;
    im_factor = (f->max_im - f->min_im) / HEIGHT;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        ci = f->max_im - y * im_factor;
        while (x < WIDTH)
        {
            cr = f->min_re + x * re_factor;
            i = mandelbrot(cr, ci);
            pixel(f, x, y, get_color(i));
            x++;
        }
        y++;
    }
}