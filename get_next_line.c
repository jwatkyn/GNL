/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:20:59 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/01 15:36:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_gnl(char buf[BUFF_SIZE + 1], char **l, int *r, const int fd)
{
	int	i;
	int j;

	i = -1;
	while (*r > 0)
	{
		j = 0;
		while (j < *r)
		{
			(*l)[++i] = buf[j++];
			if ((*l)[i] == '\n')
			{
				ft_strcpy(&buf[0], &buf[j]);
				(*l)[i] = '\0';
				return (1);
			}
		}
		*r = read(fd, &buf[0], BUFF_SIZE);
		buf[*r] = 0;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		buf[1000][BUFF_SIZE + 1];
	int				ret;
	int				i;

	if (!line || fd < 0)
		return (-1);
	if (!(*line = ft_strnew(52001)))
		return (-1);
	ret = ft_strlen(&buf[fd][0]);
	if (!ret)
		ret = read(fd, &buf[fd][0], BUFF_SIZE);
	buf[fd][ret + 1] = 0;
	i = ft_gnl((char*)(buf[fd]), &*line, &ret, fd);
	if (ft_strlen(*line) > 0 || i == 1)
		return (1);
	return (ret);
}
