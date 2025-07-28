/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:11:48 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/26 18:56:58 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_strlen_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	count_map_elements(t_game *game, char element)
{
	int	char_count;
	int	i;
	int	j;

	char_count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == element)
				char_count++;
			j++;
		}
		i++;
	}
	return (char_count);
}

void	get_map_size(t_game *game, int *width, int *height)
{
	int	y;

	y = 0;
	while (game->map[y])
		y++;
	*height = y;
	*width = 0;
	while (game->map[0][*width])
		(*width)++;
}
