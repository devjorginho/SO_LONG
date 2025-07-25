/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:16:53 by jde-carv          #+#    #+#             */
/*   Updated: 2025/07/25 22:28:33 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	move_and_finish(char *buffer)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i++] == '\n')
			break ;
	}
	while (buffer[j])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

char	*copy_to_line(char *line, char *buffer)
{
	char	*newline;
	char	*ptr;
	char	*to_free;

	newline = malloc(ft_strlen(buffer) + ft_strlen(line) + 1);
	if (!newline)
		return (NULL);
	ptr = newline;
	to_free = line;
	while (line && *line)
		*ptr++ = *line++;
	while (*buffer)
	{
		*ptr++ = *buffer;
		if (*buffer++ == '\n')
			break ;
	}
	free(to_free);
	*ptr = '\0';
	return (newline);
}

int	has_new_line(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}
