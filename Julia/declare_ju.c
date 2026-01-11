#include "../fractol.h"

void declare_jvaribles(t_fractal *f)
{
    f->min_re = -2.0;
    f->max_re = 2.0;
    f->min_im = -2.0;
    f->max_im = 2.0;
    f->zoom = 1.0;

    // f->julia_cr = -0.7;
    // f->julia_ci = 0.27015;
}