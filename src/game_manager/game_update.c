/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:36:18 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 22:56:26 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	count_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->collects_to_win = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->collects_to_win++;
			x++;
		}
		y++;
	}
}

void	check_end_game(t_game *game)
{
	if (game->game_over)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
}
