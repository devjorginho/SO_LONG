/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:52:04 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 19:58:36 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "so_long.h"
# define MAX_KEY_MAP 70000

typedef struct s_game
{
	int			w;
	int			h;
	int			game_over;
	int			collects_to_win;
	int			keymap[MAX_KEY_MAP];
	char		**map;
	void		*mlx;
	void		*window;
	t_image		*img;
	t_player	*player;
}				t_game;

#endif