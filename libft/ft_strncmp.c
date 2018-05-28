/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:52:00 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/24 17:02:15 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 1;
	while (*str1 == *str2)
	{
		if (!*str1++ || i++ == n)
			return (0);
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
