#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal f;

    ft_bzero(&f, sizeof(t_fractal));
    if (parsing(&f, argc, argv))
        return (1);
    init_fractal(&f);
    return (0);
}
