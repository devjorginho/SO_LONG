/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:50:27 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/26 17:32:25 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	draw_tile(t_game *game, char object, int x, int y)
{
	if (object == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img->wall_img, x
			* 32, y * 32);
	else if (object == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->img->collect_img,
			x * 32, y * 32);
	else if (object == 'E')
	{
		if (game->player->x == x && game->player->y == y)
			mlx_put_image_to_window(game->mlx, game->window,
				game->img->player_on_exit, x * 32, y * 32);
		else
			mlx_put_image_to_window(game->mlx, game->window,
				game->img->exit_img, x * 32, y * 32);
	}
	else if (object == '0' && game->player->x == x && game->player->y == y)
		mlx_put_image_to_window(game->mlx, game->window, game->img->player_img,
			x * 32, y * 32);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->img->floor_img, x
			* 32, y * 32);
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
			game->img->player_on_exit, x * 32, y * 32);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->img->player_img,
			x * 32, y * 32);
}

void	render_map(t_game *game)
{
	draw_map(game);
	draw_player(game);
}
