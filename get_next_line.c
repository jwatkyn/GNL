/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:38:30 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/28 15:01:33 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void	ft_getfile(int fd, t_list *fdlist)
{
	t_list	*file;

	while (((t_list*)fdlist->content)->fd != fd && fdlist->next)
		if (fdlist->next)
			flist = flist->next;
	if (((t_list*)fdlist->content)->fd != fd)
	{
		file = (t_line*)malloc(sizeof(t_line));
		file = {fd, ft_strnew(BUFF_SIZE), 0, 0, 2};
		fdlist->next = ft_strnew(file, sizeof(t_list));
		fdlist = fdlist->next;
		fdlist->content = file
	}
	if (file->ret = read(file->fd, NULL, 0) < 0)
		;
	else
		file = fdlist->content;
	return (file);
	
}

static t_line	*ft_getline(t_line *file, int fd)
{
	char	*line
	char	*temp;
	int		i;

	i = 0;
	file->len = 0;
	line = "";
	if (file->linepos == 0)
		file->ret = read(file->fd, file->line_buf, BUFF_SIZE);
	temp = (char*)malloc(sizeof(char) * BUFF_SIZE);
	while (temp[i++] = ft_char(file) != '\n' && ft_char(file) != 0)
	{
		file->linepos = file->linepos + 1;
		file->len = file->len + 1;
		if (file->linepos == BUFF_SIZE)
		{
			file->linepos = 1;
			file->ret = read(file->fd, file->line_buf, BUFF_SIZE);
			if (file->ret == 0)
				break ;
			line = ft_strmerge(line, temp);
			temp = (char*)malloc(sizeof(char) * BUFF_SIZE);
		}
	}
	return (line);	
}

static char	*ft_char(t_line *file)
{
	file->linepos = file->linepos + 1;
	file->len = file->len + 1;
}

static void	*ft_cleanfile(t_line *file)
{

}

int		get_next_line(const int fd, char **line)
{
	char		*temp;
	t_line		*file;
	static t_list	*fdlist;
	
	if (fd < 0 || !line)
		return (-1);
	if (!fdlist)
	{
		file = (t_list*)malloc(sizeof(t_list));
		file = {fd, ft_strnew(BUFF_SIZE), 0, 0, 2};
		fdlist = ft_lstnew(file, sizeof(t_line));
	}

	file = ft_getfile(fd, fdlist);
	*line = ft_getline(file, fd);
	ft_cleanfile(&fdlist);
	return (file->ret);
}
