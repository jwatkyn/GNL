/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:39:57 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/28 10:05:04 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 32

typedef struct	s_line
{
	int		fd;
	char	*line_buf;
	size_t	len;
	size_t	linepos;
	int		ret;
}				t_line;

#endif
