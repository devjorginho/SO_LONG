/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:40:40 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 23:00:53 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	count_map_lines(int fd)
{
	int		count;
	char	c;
	int		line_ret;

	count = 0;
	line_ret = read(fd, &c, 1);
	if (line_ret < 0)
		return (-1);
	while (line_ret > 0)
	{
		if (c == '\n')
			count++;
		line_ret = read(fd, &c, 1);
		if (line_ret < 0)
			return (-1);
	}
	return (count + 1);
}

char	**read_map(t_game *game, const char *map_path)
{
	int		fd;
	int		i;
	char	*line;
	int		len;

	i = 0;
	fd = open(map_path, O_RDONLY);
	game->map = ft_calloc(count_map_lines(fd) + 1, sizeof(char *));
	if (!game->map)
		return (NULL);
	close(fd);
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
	return (game->map);
}

void	validate_game_map(t_game *game)
{
	if (!check_map_rectangular(game))
		free_map(game->map);
	if (!check_map_arround(game))
		free_map(game->map);
	if (!validate_map_elements(game))
		free_map(game->map);
	if (!is_map_valid(game->map))
	{
		free_map(game->map);
		print_error_and_exit("Error: The map cannot be completed.\n");
	}
	ft_putstr("Map validated. Game started.");
}

void	create_window_with_map_size(t_game *game)
{
	int	map_width;
	int	map_height;
	int	window_width;
	int	window_height;

	get_map_size(game, &map_width, &map_height);
	window_width = map_width * 64;
	window_height = map_height * 64;
	game->window = mlx_new_window(game->mlx, window_width, window_height,
			"so_long");
	if (!game->window)
		print_error_and_exit("Error: mlx_new_window failed\n");
}
