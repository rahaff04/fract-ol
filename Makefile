NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11 -lm
SRC = main.c \
	  init.c \
	  draw.c \
	  image.c \
	  events.c 
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

