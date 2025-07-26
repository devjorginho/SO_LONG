/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_for_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:36:56 by jde-carv          #+#    #+#             */
/*   Updated: 2025/07/26 19:17:44 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_img(t_game *game, t_image *img)
{
	if (game && img)
		mlx_destroy_image(game->mlx, img);
}

int	free_for_all(t_game *game, char *error_msg)
{
	free_img(game, game->img->collect_img);
	free_img(game, game->img->player_img);
	free_img(game, game->img->floor_img);
	free_img(game, game->img->wall_img);
	free_img(game, game->img->exit_img);
	free_img(game, game->img->player_on_exit);
	if (game->img)
		free(game->img);
	if (game->player)
		free(game->player);
	if (game->map)
		free_map(game->map);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (error_msg)
		print_error_and_exit(error_msg);
	return (0);
}
