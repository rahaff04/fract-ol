#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "./mlx.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100
#define MOVE_STEP 0.2

typedef enum e_type
{
    MANDELBROT,
    JULIA,
} t_type;
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
    double zoom;
    t_type type;
} t_fractal;

int ft_strncmp(char *s1, char *s2, size_t n);
void create_img(t_fractal *f);
void pixel(t_fractal *f, int x, int y, int color);
int get_color (int i);
int mandelbrot(double cr, double ci);
void draw_mandelbrot(t_fractal *f);
int mouse_zoom(int button, int x, int y, t_fractal *f);
int key_hook_up_down(int keycode, t_fractal *f);
int key_hook_left_right(int keycode, t_fractal *f);
int key_event(int keycode, t_fractal *f);
int close_window(t_fractal *f);
void init_fractal(t_fractal *f);
# endif