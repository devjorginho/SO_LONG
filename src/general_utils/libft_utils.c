/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:26:08 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 23:03:24 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*((unsigned char *)s + n) = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*ptr;

	bytes = nmemb * size;
	if (size && ((bytes / size) != nmemb))
		return (NULL);
	ptr = malloc(bytes);
	if (NULL == ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}

void	ft_putstr(char *s)
{
	ssize_t	ret;

	if (!s || !*s)
		return ;
	while (*s)
		ret = write(1, s++, 1);
	if (!ret)
		return ;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		len;

	len = ft_strlen(s1);
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, len + 1);
	return (s2);
}
