# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralamair <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 15:57:35 by ralamair          #+#    #+#              #
#    Updated: 2026/01/21 15:57:38 by ralamair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

MLXDIR = minilibx-linux
MLXLIB = $(MLXDIR)/libmlx.a

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

all: $(MLXLIB) $(NAME)

$(MLXLIB):
	make -C $(MLXDIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXLIB) -lXext -lX11 -lm -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re
