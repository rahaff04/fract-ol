#include "fractol.h"


static void malloc_error(void)
{
    write(2, "Error: Memory allocation failed\n", 33);
    exit(EXIT_FAILURE);
}

void	init_fractol(t_fractol *f)
{
    f->mlx_con = mlx_init();
    if (!f->mlx_con)
        malloc_error();
    f->mlx_win = mlx_new_window(f->mlx_con, WIDTH, HEIGHT, f->name);
    if (!f->mlx_win)
    {
        mlx_destroy_display(f->mlx_con);
        free(f->mlx_con);
        malloc_error();
    }

    f->img->imgptr = mlx_new_image(f->mlx_con, WIDTH, HEIGHT);
    if (!f->img->imgptr)
    {
        mlx_destroy_window(f->mlx_con, f->mlx_win);
        mlx_destroy_display(f->mlx_con);
        free(f->mlx_con);
        malloc_error();
    }
    
    f->img->pixils = mlx_get_data_addr(f->img->imgptr, &f->img->bpp, &f->img->line_len, &f->img->endian);
    //events_init(f);
    //data_init(f);
}
