#include "fractol.h"

int parsing(t_fractal *f,int ac, char **av)
{
    if (ac != 2)
    {
        write(2, "Usage: ./fractol <fractal_type>\n", 32);
        return (1);
    }
    if (!ft_strncmp(av[1], "mandelbrot", 10))
        f->type = MANDELBROT;
    else if (ft_strncmp(av[1], "julia", 5) == 0)
        f->type = JULIA;
    else
    {
        write(2, "Error: Invalid fractal type. Use mandelbrot or julia\n", 54);
        return (1);
    }
    return (0);
}