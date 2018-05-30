/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:38:30 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/30 15:52:02 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

static t_line	*ft_getfile(int fd, t_list *fdlist)
{
	t_line	*file;
	
	while (((t_line*)(fdlist->content))->fd != fd && fdlist->next)
		if (fdlist->next)
			fdlist = fdlist->next;
	if (((t_line*)fdlist->content)->fd != fd)
	{
		file = (t_line*)malloc(sizeof(t_line));
		*file = (t_line){fd, ft_strnew(BUFF_SIZE), 0, 0, 2};
		fdlist->next = ft_lstnew(file, sizeof(t_line));
		fdlist = fdlist->next;
		fdlist->content = file;
	}
	else
		file = fdlist->content;
	if ((file->ret = read(file->fd, NULL, 0)) < 0)
		;
	else
		file = fdlist->content;
	return (file);
}

static char	ft_char(t_line *file)
{
	char	c;

	if ((int)(file->linepos) == file->ret)
	{
			file->linepos = 0;
			ft_strdel(&(file->line_buf));
			file->line_buf = ft_strnew(BUFF_SIZE);
			file->ret = read(file->fd, file->line_buf, BUFF_SIZE);
			printf("%d\n", file->ret);
			printf("%s\n", file->line_buf);
	}
	++file->linepos
	file->len = file->len + 1;
	return (file->line_buf[file->linepos - 1]);
}

static void	ft_cleanfile(t_list **fdlist)
{
	t_line	*file;
	t_list	*temp;
	t_list	*temp2;

	temp = *fdlist;
	while (temp->next->next && ((t_line*)(temp->next->content))->ret == BUFF_SIZE)
		temp = temp->next;
	temp2 = temp->next;
	file = temp2->content;
	temp->next = temp2->next;
	if (file->ret < BUFF_SIZE)
	{
		ft_strdel(&(file->line_buf));
		free(file);
		free(temp2);
	}
}

static char		*ft_getline(t_line *file)
{
	char	*line;
	char	*ret;
	size_t	i;
	size_t	end;

	end = 32;
	i = 0;
	if (file->linepos == 0)
		file->ret = read(file->fd, file->line_buf, BUFF_SIZE);
	ret = ft_strnew(end);
	while ((ret[i] = ft_char(file)) != '\n' && ret[i] > 0)
	{
		i++;
		printf("d");
		if (i == end - 1)
		{
			end = end + end;
			line = ft_strnew(end);
			ft_strcpy(line, ret);
			ft_strdel(&ret);
			ret = line;
		}
		printf("%c - %zu ", ret[i - 1], i);
		printf("%zu \n", ft_strlen(ret));
		//printf("%s\n", line);
	}
	if (ret[i] == '\n')
		ret[i] = '\0';
	ft_strdel(&line);
	return (ret);	
}


int		get_next_line(const int fd, char **line)
{
	t_line			*file;
	static t_list	*fdlist;
	int				ret;

	
	if (fd < 0 || !line)
		return (-1);
	if (!fdlist)
	{
		
		file = (t_line*)malloc(sizeof(t_line));
		*file = (t_line){fd, ft_strnew(BUFF_SIZE), 0, 0, 2};
		fdlist = ft_lstnew(file, sizeof(t_line));
		ft_memdel((void**)&file);
	}
	file = ft_getfile(fd, fdlist);	
	*line = ft_getline(file);
	ret = file->ret;
	printf("%s", *line);
	ft_cleanfile(&fdlist);
	if (ret == BUFF_SIZE)
		return (1);
	else
		return (0);
}
