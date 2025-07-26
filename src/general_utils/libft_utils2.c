/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:08:27 by jde-carv          #+#    #+#             */
/*   Updated: 2025/07/26 20:19:40 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static size_t	int_len(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + int_len(n / 10));
}

static unsigned int	itou(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	un;
	size_t			len;

	un = itou(n);
	len = int_len(un);
	if (n < 0)
		len += 1;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (un % 10);
		un /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
