/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:52:39 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/24 22:20:02 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t len_n;
	size_t i;

	if (!*little)
		return ((char*)(big));
	if (!*big)
		return (NULL);
	if (!len || (len_n = ft_strlen(little)) > ft_strlen(big) || len_n > len)
		return (NULL);
	i = 1;
	while (*big && ft_strncmp(big, little, len_n))
	{
		if (i++ > len - len_n)
		{
			return (NULL);
		}
		big++;
	}
	return ((char*)(big));
}
