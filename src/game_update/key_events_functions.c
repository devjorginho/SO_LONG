/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:03:54 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/28 11:01:32 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	keydown(int keycode, t_game *game)
{
	t_game	to_free;

	to_free = *game;
	if (keycode == 65307)
	{
		free_for_all(&to_free, NULL);
		exit(0);
	}
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		move_player(game, keycode);
	return (0);
}

int	keyup(int keycode, t_game *game)
{
	game->keymap[keycode] = 0;
	return (0);
}
int	close_game_with_x(t_game *game)
{
	free_for_all(game, NULL);
	exit(0);
}


