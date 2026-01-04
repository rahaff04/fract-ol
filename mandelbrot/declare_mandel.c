#include "../fractol.h"

void declare_mvaribles(t_fractal *f)
{
    f->min_re = -2.0;
    f->max_re = 1.0;
    f->min_im = -1.2;
    f->max_im = 1.5;
    f->zoom = 1.0;
}