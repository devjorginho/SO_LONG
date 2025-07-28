NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iinc -g

MLX_DIR	= ./minilibx-linux
MLX_LIB	= $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm

SRCS	= 	./src/game_update/game_update.c \
			./src/game_update/key_events_functions.c \
			./src/main.c \
			./src/general_utils/get_next_line.c \
			./src/general_utils/error_messages.c \
			./src/general_utils/libft_utils2.c \
			./src/general_utils/free_for_all.c \
			./src/general_utils/libft_utils.c \
			./src/general_utils/get_next_line_utils.c \
			./src/map_functions/map_utils.c \
			./src/map_functions/map_elements_checker.c \
			./src/map_functions/map_completability_checker.c \
			./src/map_functions/check_map_walls.c \
			./src/map_functions/read_map.c \
			./src/draw_functions/draw_image.c \
			./src/draw_functions/load_images.c \
			./src/setup_game/game_init.c \
			./src/setup_game/arguments_checker.c

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

fclean: clean
	rm -f $(NAME)

re: fclean all

val: 
	valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/def.ber

.PHONY: all clean fclean re mlx
