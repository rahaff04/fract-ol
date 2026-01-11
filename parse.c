#include "fractol.h"

static int parse_julia(t_fractal *f, int ac, char **av)
{
    if (ac != 4)
    {
        write (2, "./fractol julia <real> <imgaginary>\n", 31);
        return (1);
    }
    f->julia_cr = atof(av[2]);
    f->julia_ci = atof(av[3]);
    if (f->julia_cr < -2.0 || f->julia_cr > 2.0 || f->julia_ci < -2.0 || f->julia_ci > 2.0)
    {
        write(2, "Error: Julia parameters should be between [-2.0, 2.0]\n", 54);
        return (1);
    }
    return (0);
}
int parsing(t_fractal *f,int ac, char **av)
{
    if (ac < 2)
    {
        write(2, "./fractol <fractal_name> [julia_parameters]\n", 41);
        return (1);
    }
    if (ft_strncmp(av[1], "mandelbrot", 11) == 0 && ac == 2)
    {
        f->type = MANDELBROT;
        return (0);
    }
    else if (ft_strncmp(av[1], "julia", 6) == 0)
    {
        f->type = JULIA;
        return (parse_julia(f, ac, av));
    }
    else
    {
        write(2, "Error: Unknown fractal name. \n",31);
        return (1);
    } 
}