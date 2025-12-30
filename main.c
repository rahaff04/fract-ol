#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal f;

    if (argc != 2)
    {
        write(2, "Usage: ./mandelbrot\n", 20);
        return (1);
    }
    if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
    {
        f.type = MANDELBROT;
    }
    else if (ft_strncmp(argv[1], "julia", 5) == 0)
    {
        f.type = JULIA;
    }
    else
    {
        write(2, "Error: Invalid fractal type. Use mandelbrot, julia, or burning_ship\n", 67);
        return (1);
    }
    init_fractal(&f);
    return (0);
}
