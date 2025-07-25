/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:05:11 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 22:46:07 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	image_loader(t_game *game, void **img_ptr, char *path)
{
	*img_ptr = mlx_xpm_file_to_image(game->mlx, path, &game->img->w,
			&game->img->h);
	if (!*img_ptr)
		return ;
}

void	load_xpm_to_image(t_game *game)
{
	game->img = malloc(sizeof(t_image));
	if (!game->img)
		return ;
	game->img->w = 64;
	game->img->h = 64;
	image_loader(game, (void **)&game->img->player_on_exit,
		"assets/player_on_exit.xpm");
	image_loader(game, (void **)&game->img->wall_img, "assets/wall.xpm");
	image_loader(game, (void **)&game->img->floor_img, "assets/floor.xpm");
	image_loader(game, (void **)&game->img->player_img, "assets/player.xpm");
	image_loader(game, (void **)&game->img->collect_img, "assets/collect.xpm");
	image_loader(game, (void **)&game->img->exit_img, "assets/exit.xpm");
}
