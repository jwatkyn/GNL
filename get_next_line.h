/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:39:57 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/30 15:51:57 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 36

int				get_next_line(const int fd, char **line);

typedef struct	s_line
{
	int		fd;
	char	*line_buf;
	size_t	len;
	size_t	linepos;
	int		ret;
}				t_line;

#endif
