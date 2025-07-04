/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:38:22 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/23 17:31:57 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_background(t_game *game)
{
	game->bg_img = mlx_xpm_file_to_image(game->mlx, "assets/background/background.xpm", &game->bg_width, &game->bg_height);
}
