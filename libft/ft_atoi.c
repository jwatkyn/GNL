/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:48:04 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/24 16:58:53 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_white(char c)
{
	if ((c > 8 && c < 14) || c == ' ')
		return (1);
	else
		return (0);
}

static void	ft_sign(int sign, unsigned long *cut)
{
	*cut = (unsigned long)LONG_MAX / 10;
	if (sign == -1)
		*cut = (-(unsigned long)LONG_MIN) / 10;
}

static int	ft_end(int sign, unsigned long cut, char c, unsigned long *n)
{
	if (*n > cut || (*n == cut && c - '0' > (int)(cut * 10 % 10)))
	{
		*n = LONG_MAX;
		if (sign == -1)
			*n = LONG_MIN;
		return (1);
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long	n;
	int				sign;
	unsigned long	cut;

	n = 0;
	sign = 1;
	if (!*str)
		return (0);
	while (ft_white(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	ft_sign(sign, &cut);
	while (ft_isdigit(*str) && *str != '\0')
	{
		n = n * 10 + *str++ - '0';
		if (ft_end(sign, cut, *str, &n))
			break ;
	}
	return ((int)n * sign);
}
