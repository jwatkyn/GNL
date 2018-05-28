/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:04:34 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/21 08:04:36 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*aux;

	if (alst && *alst)
	{
		current = *alst;
		while (current)
		{
			(*del)(current->content, current->content_size);
			aux = current->next;
			free(current);
			current = aux;
		}
		*alst = NULL;
	}
}
