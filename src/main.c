/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:32:09 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/28 11:33:55 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game;

	validate_arguments_and_map(argc, argv, &game);
	validate_game_map(&game);
	count_collectibles(&game);
	create_player(&game);
	init_mlx_and_window(&game);
	free_for_all(&game, NULL);
	return (0);
}
