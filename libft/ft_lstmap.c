/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:05:36 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/05/21 08:05:38 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*crt;

	crt = (*f)(lst);
	if (!crt)
		return (NULL);
	new = crt;
	lst = lst->next;
	while (lst)
	{
		crt->next = (*f)(lst);
		if (crt->next == NULL)
			return (NULL);
		crt = crt->next;
		lst = lst->next;
	}
	return (new);
}
