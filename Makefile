# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralamair <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 10:27:41 by ralamair          #+#    #+#              #
#    Updated: 2026/01/12 10:28:15 by ralamair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -lXext -lX11 -lm -lz

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
	  utils/ft_bzero.c

OBJ = $(SRC:.c=.o)

all: $(MLX_LIB) $(NAME)

# build mlx if not built
$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
