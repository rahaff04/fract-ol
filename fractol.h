#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "./mlx.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 1000

typedef struct s_fractal
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
    double min_re;
    double max_re;
    double min_im;
    double max_im;
} t_fractal;

void create_img(t_fractal *f);
void pixel(t_fractal *f, int x, int y, int color);
int mandelbrot(double cr, double ci);
void draw_mandelbrot(t_fractal *f);
void init_fractal(t_fractal *f);
# endif