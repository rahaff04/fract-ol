NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11 -lm
SRC = main.c \
          parse.c \
          init.c \
          mandelbrot/declare_mandel.c \
          mandelbrot/draw_mandel.c \
          mandelbrot/mouse_events_ma.c \
          mandelbrot/events_key_ma.c \
          Julia/declare_ju.c \
          Julia/draw_julia.c \
          Julia/mouse_event_ju.c \
          Julia/key_events_ju.c \
          image.c \
          close.c \
          utils/ft_strncmp.c \
          utils/ft_bzero.c \
		  utils/ft_atof.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re