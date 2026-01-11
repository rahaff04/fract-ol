#include "fractol.h"

void init_mandel(t_fractal *f)
{
    declare_mvaribles(f);
    if (create_img(f) != 0)
        return;
    draw_mandelbrot(f);
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
    mlx_hook(f->win, 17, 0, close_window, f);
    mlx_mouse_hook(f->win, mouse_zoom_ma, f);
    mlx_key_hook(f->win, key_event_ma, f);
}

void init_julia(t_fractal *f)
{
    declare_jvaribles(f);
    if (create_img(f) != 0)
        return;
    draw_julia(f);
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
    mlx_hook(f->win, 17, 0, close_window, f);
    mlx_mouse_hook(f->win, mouse_zoom_ju, f);
    mlx_key_hook(f->win, key_event_ju, f);
}
int init_fractal(t_fractal *f)
{
    f->mlx = mlx_init();
    if (!f->mlx)
        return(1);
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
    if (!f->win)
        return(1);
    if (f->type == MANDELBROT)
        init_mandel(f);
    else if (f->type == JULIA)
        init_julia(f);  
    //mlx_loop(f->mlx);
    return (0);
}




