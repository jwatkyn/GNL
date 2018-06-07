/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:20:59 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/06/06 11:40:56 by jwatkyn          ###   ########.fr       */
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
	if (i >= 0)
		return (1);
	else
		return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		buf[INT_MAX][BUFF_SIZE + 1];
	int				ret;
	int				i;

	if (line == NULL || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!(*line = (char *)malloc(5200000)))
		return (-1);
	ret = ft_strlen(&buf[fd][0]);
	if (!ret)
		ret = read(fd, &buf[fd][0], BUFF_SIZE);
	buf[fd][ret] = 0;
	i = ft_gnl((char*)(buf[fd]), &*line, &ret, fd);
	if (ft_strlen(*line) > 0 || i == 1)
		return (1);
	return (ret);
}
