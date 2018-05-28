/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:06:37 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/21 08:44:45 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = (char*)malloc(sizeof(char) * (1 + len));
	if (!(s2))
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
