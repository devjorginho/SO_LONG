NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iinc -g -O3

MLX_DIR	= ./minilibx-linux
MLX_LIB	= $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm

SRCS	= $(shell find ./src -name "*.c")
OBJS	= $(SRCS:.c=.o)

all: mlx $(NAME)

mlx:
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

val: 
	valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map5.ber

.PHONY: all clean fclean re mlx
