NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iinc

MLX_DIR	= ./minilibx-linux
MLX_LIB	= $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm

SRCS	= ./src/check_map_functions/check_map_walls.c \
		  ./src/check_map_functions/map_completability_checker.c \
		  ./src/check_map_functions/map_elements_checker.c \
		  ./src/check_map_functions/map_utils.c \
		  ./src/check_map_functions/read_map.c \
		  ./src/game_manager/game_update.c \
		  ./src/game_manager/key_events_functions.c \
		  ./src/game_manager/free_for_all.c \
		  ./src/general_utils/error_messages.c \
		  ./src/general_utils/get_next_line.c \
		  ./src/general_utils/get_next_line_utils.c \
		  ./src/general_utils/libft_utils.c \
		  ./src/image_functions/draw_image.c \
		  ./src/image_functions/load_images.c \
		  ./src/main.c \
		  ./src/setup_game/arguments_checker.c \
		  ./src/setup_game/game_init.c \
		  ./src/general_utils/libft_utils2.c

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
