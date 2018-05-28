/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:51:15 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/22 07:49:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t max_len)
{
	size_t len;

	len = 0;
	while (len < max_len && s[len])
		len++;
	return (len);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t i;

	i = ft_strnlen(dst, size);
	len = i + ft_strlen(src);
	if (i == size)
		return (len);
	while (*src && i < size)
		dst[i++] = *src++;
	if (i == size)
		i--;
	dst[i] = '\0';
	return (len);
}
