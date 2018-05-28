/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:03:33 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/24 22:39:07 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *s, char c)
{
	int count;

	count = 0;
	if (*s)
	{
		while (*s != c && *s)
		{
			count++;
			s++;
		}
	}
	return (count);
}

static int	ft_countwords(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		while (*s == c)
			s++;
		count++;
	}
	count++;
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(words = (char**)ft_memalloc(sizeof(char *) * ft_countwords(s, c))))
		return (NULL);
	while (*s == c)
		s++;
	while (*s)
	{
		len = ft_wordlen(s, c);
		if (!(words[i] = ft_strnew(len)))
			return (NULL);
		ft_strncpy(words[i++], s, len);
		while (*s && *s != c)
			s++;
		while (*s == c)
			s++;
	}
	return (words);
}
