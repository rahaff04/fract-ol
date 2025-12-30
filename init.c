#include "fractol.h"

void declare_varibles(t_fractal *f)
{
    f->min_re = -2.0;
    f->max_re = 1.0;
    f->min_im = -1.2;
    f->max_im = 1.5;
    f->zoom = 1.0;
}

void init_fractal(t_fractal *f)
{
    f->mlx = mlx_init();
    if (!f->mlx)
        exit(1);
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
    if (!f->win)
        exit(1);
    if (f->type == MANDELBROT)
    {
        declare_varibles(f);
        create_img(f);
        draw_mandelbrot(f);
        mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
        mlx_hook(f->win, 17, 0, (void *)exit, NULL);
        mlx_mouse_hook(f->win, mouse_zoom, f);
        mlx_key_hook(f->win, key_event, f);
    }
    mlx_loop(f->mlx);
}




