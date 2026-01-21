
*This project has been created as part of the 42 curriculum by ralamair*

## Description

A simple graphical program that visualizes mathematical fractals using MiniLibX.
The project renders Mandelbrot and Julia sets with interactive controls.

## Fractals
- Mandelbrot

![Mandelbrot fractal](https://upload.wikimedia.org/wikipedia/commons/2/21/Mandel_zoom_00_mandelbrot_set.jpg)

- Julia

![Julia fractal](https://upload.wikimedia.org/wikipedia/commons/7/7e/Julia_0.4_0.6.png)

## Instructions

## Compilation
```bash
make
./fractol mandelbrot
./fractol julia <real> <imaginary>
```
## Controls
- Mouse wheel: Zoom in / Zoom out
- Arrow keys: Move the view
- ESC or window close: Exit program

## Notes

- Each pixel represents a complex number

- Colors depend on the number of iterations before divergence

- Points that do not diverge are colored black

- Julia parameters must be between [-2.0, 2.0]

## Resources

- https://www.karlsims.com/julia.html
- https://qst0.github.io/ft_libgfx/man_mlx.html
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

## Libraries

- **MiniLibX**:  
  A minimal graphics library in C used to handle windows, images, and user input.  
  In this project, it allows:
  - Creating a window for the fractals
  - Drawing pixels directly to an image buffer
  - Handling keyboard and mouse events for interaction
  - Updating the display efficiently with `mlx_put_image_to_window`
  
  Using MiniLibX makes it easy to implement interactive fractals without dealing with complex graphics APIs.

- **stdlib.h**: Memory allocation (`malloc`) and NULL checks
- **unistd.h**: Writing error messages (`write`)
