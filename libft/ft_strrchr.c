/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:52:55 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/24 21:10:48 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	chr;

	chr = c;
	len = (int)(ft_strlen(str));
	while (len >= 0)
	{
		if (str[len] == chr)
			return ((char*)(str + len));
		len--;
	}
	return (NULL);
}
