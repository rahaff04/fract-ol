#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal f;
    (void)argv;
    if (argc != 1)
    {
        write(2, "Usage: ./fractol\n", 17);
        return (1);
    }
    init_fractal(&f);
    return (0);
}
