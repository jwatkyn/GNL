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


static t_line	*ft_getfile(int fd, t_list *fdlist)
{
	t_line	*file;
	int	ret;
	
	while (((t_line*)(fdlist->content))->fd != fd && fdlist->next)
		if (fdlist->next)
			fdlist = fdlist->next;
	if (((t_line*)fdlist->content)->fd != fd)
	{
		file = (t_line*)ft_memalloc(sizeof(t_line));
		*file = (t_line){fd, ft_strnew(BUFF_SIZE), 0, 0, 1};
		fdlist->next = ft_lstnew(file, sizeof(t_line));
		file = (t_line*)fdlist->next->content;
	}
	else
		file = (t_line*)fdlist->content;
	if ((ret = read(file->fd, NULL, 0)) < 0)
		file->ret = ret;
	return (file);
}

static char	ft_char(t_line *file)
{
	int ret;
	if (file->linepos == file->len)
	{
			ret = read(file->fd, file->line, BUFF_SIZE);
			if (ret <= 0)
			{
				file->ret = ret;
				return (ret);
			}
			file->len = ret;
			file->linepos = 0;
	}
	++file->linepos;
	return (file->line[file->linepos - 1]);

}

static void	ft_cleanfile(t_list **fdlist)
{
	t_list	*current;
	t_list	*next;
	t_line	*file;

	current = *fdlist;
	while (current)
	{
		file = (t_line*)current->content;
		next = current->next;
		if (file->ret <= 0)
		{
			if (current == *fdlist)
				*fdlist = next;
			ft_strdel(&file->line);
		}
		current = next;
	}
}

static void			ft_getline(t_line *file, char **buf)
{
	char	*line;
	char	*ret;
	size_t	i;
	size_t	end;

	end = 10;
	i = 0;
	ret = ft_strnew(end);
	while ((ret[i] = ft_char(file)) != '\n' && ret[i] > 0)
	{
		i++;
		if (i == end - 1)
		{
			end *= 2;
			line = ft_strnew(end);
			ft_strcpy(line, ret);
			ft_strdel(&ret);
			ret = line;
		}
	}
	if (ret[i] == '\n')
		ret[i] = '\0';
	*buf = ret;
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
		*file = (t_line){fd, ft_strnew(BUFF_SIZE), 0, 0, 1};
		fdlist = ft_lstnew(file, sizeof(t_line));
		ft_memdel((void**)&file);
	}
	file = ft_getfile(fd, fdlist);	
	ft_getline(file, line);
	if (file->ret >= 0 && ft_strlen(*line))
		ret = 1;
	else
		ret = file->ret;
	ft_cleanfile(&fdlist);
	return (ret);
}
