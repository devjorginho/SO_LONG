/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:50:27 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 21:14:28 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	draw_tile(t_game *game, char object, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img->floor_img, x
		* 64, y * 64);
	if (object == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img->wall_img, x
			* 64, y * 64);
	else if (object == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->img->collect_img,
			x * 64, y * 64);
	else if (object == 'E')
	{
		if (game->player->x == x && game->player->y == y)
			mlx_put_image_to_window(game->mlx, game->window,
				game->img->player_on_exit, x * 64, y * 64);
		else
			mlx_put_image_to_window(game->mlx, game->window,
				game->img->exit_img, x * 64, y * 64);
	}
	else if (object == '0' && game->player->x == x && game->player->y == y)
		mlx_put_image_to_window(game->mlx, game->window, game->img->player_img,
			x * 64, y * 64);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->player_on_exit, x * 64, y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->img->player_img,
			x * 64, y * 64);
}

void	render_map(t_game *game)
{
	draw_map(game);
	draw_player(game);
}
