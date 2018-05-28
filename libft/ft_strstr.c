/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:53:07 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/17 14:42:56 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t len;

	if (!*needle)
		return ((char*)(haystack));
	len = ft_strlen(needle);
	while (*haystack && ft_strncmp(haystack, needle, len))
		haystack++;
	if (*haystack)
		return ((char*)(haystack));
	return (NULL);
}
