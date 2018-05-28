/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:51:48 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/23 10:13:16 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t counter;
	size_t i;

	counter = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (*src && counter < n)
	{
		dest[i] = *src;
		i++;
		src++;
		counter++;
	}
	dest[i] = '\0';
	return (dest);
}
