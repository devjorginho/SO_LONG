/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_completability_checker.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:44:43 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/26 18:51:42 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	**dup_map(char **map)
{
	char	**duplicated;
	int		i;
	int		lines;

	i = 0;
	lines = ft_strlen_map(map);
	duplicated = ft_calloc(lines + 1, sizeof(char *));
	if (!duplicated)
		return (NULL);
	while (i < lines)
	{
		duplicated[i] = ft_strdup(map[i]);
		if (!duplicated[i])
		{
			while (i-- > 0)
				free(duplicated[i]);
			free(duplicated);
			return (NULL);
		}
		i++;
	}
	duplicated[i] = NULL;
	return (duplicated);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
		map[y][x] = 'V';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}

void	fill_the_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				flood_fill(map, y, x);
				return ;
			}
			x++;
		}
		y++;
	}
}

int	has_collectable_and_exit(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_map_valid(char **original_map)
{
	char	**copy;

	copy = dup_map(original_map);
	if (!copy)
		return (0);
	fill_the_map(copy);
	if (has_collectable_and_exit(copy))
	{
		free_map(copy);
		return (0);
	}
	free_map(copy);
	return (1);
}
