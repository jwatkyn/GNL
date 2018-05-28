/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:44:47 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/23 09:50:26 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (n)
	{
		s1 = (unsigned char *)str1;
		s2 = (unsigned char *)str2;
		i = 0;
		while (i < n)
		{
			if (*s1 != *s2)
				return (*s1 - *s2);
			s1++;
			s2++;
			i++;
		}
	}
	return (0);
}
