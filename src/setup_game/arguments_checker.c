/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:21:46 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 23:14:43 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_map_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

void	validate_arguments_and_map(int argc, char **argv, t_game *game)
{
	int	line_count;

	if (argc != 2)
		print_error_and_exit("Try ./so_long <path/map.ber>\n");
	if (!check_map_name(argv[1]))
		print_error_and_exit("Invalid arguments, map must end with .ber\n");
	game->map = read_map(game, argv[1]);
	if (!game->map)
		print_error_and_exit("Error: Failed to read map\n");
	line_count = 0;
	while (game->map[line_count])
		line_count++;
	if (line_count < 3)
		print_error_and_exit("Invalid map\n");
}
