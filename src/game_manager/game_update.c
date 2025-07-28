/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:36:18 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/28 10:51:18 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	collision_checker(t_game *game, int new_x, int new_y)
{
	char	area;

	area = game->map[new_y][new_x];
	if (area == '1')
		return (0);
	if (area == 'C')
	{
		game->player->collects++;
		game->map[new_y][new_x] = '0';
	}
	if (area == 'E')
	{
		if (game->player->collects == game->collects_to_win)
		{
			game->game_over = 1;
		}
		return (1);
	}
	return (1);
}

void	update_player_position(int keycode, int *x, int *y)
{
	if (keycode == 'w')
		(*y)--;
	else if (keycode == 's')
		(*y)++;
	else if (keycode == 'a')
		(*x)--;
	else if (keycode == 'd')
		(*x)++;
}

void	move_player(t_game *game, int keycode)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x;
	new_y = game->player->y;
	update_player_position(keycode, &new_x, &new_y);
	if (!collision_checker(game, new_x, new_y))
		return ;
	if (game->map[game->player->y][game->player->x] != 'E')
		game->map[game->player->y][game->player->x] = '0';
	if (game->map[new_y][new_x] != 'E')
		game->map[new_y][new_x] = 'P';
	game->player->x = new_x;
	game->player->y = new_y;
	game->player->moves++;
	ft_fputstr(1, "Moves: ");
	ft_putnbr(game->player->moves);
	ft_fputstr(1, "\n");
	if (game->game_over)
	{
		free_for_all(game, "You won !");
		exit(0);
	}
}
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
