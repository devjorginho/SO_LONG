/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:49:09 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 22:30:04 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_valid_chars(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			c = (game->map[i][j]);
			if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_collectables(t_game *game)
{
	return (count_map_elements(game, 'C') >= 1);
}

int	check_exit(t_game *game)
{
	return (count_map_elements(game, 'E') == 1);
}

int	check_player(t_game *game)
{
	return (count_map_elements(game, 'P') == 1);
}

int	validate_map_elements(t_game *game)
{
	if (!check_valid_chars(game))
		print_error_and_exit("Invalid elements");
	if (!check_player(game))
		print_error_and_exit("Invalid player");
	if (!check_exit(game))
		print_error_and_exit("Invalid exit");
	if (!check_collectables(game))
		print_error_and_exit("Invalid collectables");
	return (1);
}
