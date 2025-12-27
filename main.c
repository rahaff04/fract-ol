#include "fractol.h"

int main (int ac, char **av)
{
    t_fractol f;

    if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) || 4 == ac && ft_strncmp(av[1], "julia", 5)) 
    {
        // init_fractol(&f);
       f.name = av[1];
        // fractol_render(&f);
        // mlx_loop(f.mlx_con);
    }
    else
    {
        write(1, "Usage: ./fractol mandelbrot\n", 28);
        write(1, "or:    ./fractol julia <real part> <imaginary part>\n", 53);
        return (1);
    }
}