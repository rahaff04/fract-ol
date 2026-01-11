#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal f;

    ft_bzero(&f, sizeof(t_fractal));
    if (parsing(&f, argc, argv) != 0)
        return (1);
    if (init_fractal(&f) != 0)
    {
        write(2, "Error initializing fractal\n", 27);
        return (1);
    }
    mlx_loop(f.mlx); 
    return (0);
}
