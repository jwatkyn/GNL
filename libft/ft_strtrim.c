/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:39:12 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/24 22:08:05 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*start;
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	while (ft_iswhitespace(*s))
		s++;
	if (!*s)
	{
		return (ft_strdup(""));
	}
	start = (char*)s;
	len = 1;
	while (*++s)
		len++;
	while (ft_iswhitespace(*--s))
		len--;
	if (!(str = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(str, start, len));
}
