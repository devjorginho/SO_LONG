/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:58:53 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/26 18:06:16 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	create_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return ;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player->x = x;
				game->player->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_mlx_and_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error_and_exit("Error: mlx_init failed\n");
	create_window_with_map_size(game);
	load_xpm_to_image(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->window, 2, 1L << 0, keydown, game);
	mlx_hook(game->window, 3, 1L << 1, keyup, game);
	mlx_hook(game->window, 17, 0, free_for_all, game);
}

int	game_loop(t_game *game)
{
	check_end_game(game);
	render_map(game);
	return (0);
}
