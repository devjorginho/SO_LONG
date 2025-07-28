/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:17:42 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/28 10:52:28 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "image.h"
# include "player.h"
# include "game.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

// Map functions
char	**read_map(t_game *game, const char *map_path);
int		ft_strlen_map(char **map);
int		count_map_elements(t_game *game, char element);
void	create_window_with_map_size(t_game *game);
void	get_map_size(t_game *game, int *width, int *height);

// Some of protections
void	free_map(char **map);
void	validate_arguments_and_map(int argc, char **argv, t_game *game);
int		check_map_rectangular(t_game *game);
int		check_map_arround(t_game *game);
int		validate_map_elements(t_game *game);
int		is_map_valid(char **original_map);
void	init_mlx_and_window(t_game *game);
void	validate_game_map(t_game *game);
int		free_for_all(t_game *game, char *error_msg);

// Image functions
void	load_xpm_to_image(t_game *game);
void	draw_tile(t_game *game, char tile, int x, int y);
void	draw_map(t_game *game);
void	render_map(t_game *game);

// Setup game functions
int		game_loop(t_game *game);
void	check_end_game(t_game *game);
void	count_collectibles(t_game *game);

// GNL functions
char	*get_next_line(int fd);
void	move_and_finish(char *buffer);
int		has_new_line(char *s);
void	ft_putnbr(int nb);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*copy_to_line(char *line, char *buffer);
void	clean_line(char *file_line);
void	ft_putchar(char c);

// Player functions
void	create_player(t_game *game);
void	move_player(t_game *game, int keycode);
int		collision_checker(t_game *game, int new_x, int new_y);

// Key events functions
int		keydown(int keycode, t_game *game);
int		keyup(int keycode, t_game *game);
int		close_game_with_x(t_game *game);

// Utility functions
void	putstr(char *s);
char	*ft_itoa(int n);
void	print_error_and_exit(char *message);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
void	ft_fputstr(int fd, char *s);

#endif