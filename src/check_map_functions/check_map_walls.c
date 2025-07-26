/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:59:46 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/26 19:10:07 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_map_rectangular(t_game *game)
{
	int	len;
	int	i;
	int	line_len;

	len = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		line_len = (int)ft_strlen(game->map[i]);
		if (line_len != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_side_walls(char *s)
{
	while (*s)
	{
		if (*s != '1')
			return (0);
		s++;
	}
	return (1);
}

int	check_mid_walls(char **s)
{
	int	i;
	int	s_size;

	s_size = 0;
	while (s[0][s_size])
		s_size++;
	i = 1;
	while (s[i + 1])
	{
		if (s[i][0] != '1' || s[i][s_size - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_arround(t_game *game)
{
	int	last_line;

	if (!game->map || !game->map[0])
		return (0);
	last_line = 0;
	while (game->map[last_line])
		last_line++;
	last_line--;
	if (!check_side_walls(game->map[0])
		|| !check_side_walls(game->map[last_line]))
		return (0);
	if (!check_mid_walls(game->map))
		return (0);
	return (1);
}
