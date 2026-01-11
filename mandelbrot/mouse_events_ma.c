#include "../fractol.h"

int     mouse_zoom_ma(int button, int x, int y, t_fractal *f)
{
    double mouse_re;
    double mouse_im;
    double zoom_factor;

    zoom_factor = 0.1;
    if (button == 4)
        f->zoom *= (1.0 + zoom_factor);
    else if (button == 5)
        f->zoom *= (1.0 - zoom_factor);
    else
        return (0);
    mouse_re = f->min_re + (double)x * (f->max_re - f->min_re) / WIDTH;
    mouse_im = f->max_im - (double)y * (f->max_im - f->min_im) / HEIGHT;
    f->min_re = mouse_re + (f->min_re - mouse_re) / f->zoom;
    f->max_re = mouse_re + (f->max_re - mouse_re) / f->zoom;
    f->min_im = mouse_im + (f->min_im - mouse_im) / f->zoom;
    f->max_im = mouse_im + (f->max_im - mouse_im) / f->zoom;
    draw_mandelbrot(f);
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
    return (0);
}
