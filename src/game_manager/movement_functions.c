/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:03:54 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 23:00:10 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	keydown(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		move_player(game, keycode);
	return (0);
}

int	keyup(int keycode, t_game *game)
{
	game->keymap[keycode] = 0;
	return (0);
}

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
	ft_putstr("Moves: ");
	ft_putnbr(game->player->moves);
	ft_putstr("\n");
	if (game->game_over)
	{
		ft_putstr("You won, congratulations!\n");
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
}
