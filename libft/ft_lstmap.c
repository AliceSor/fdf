/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:23:43 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 18:45:21 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (lst && f)
	{
		start = f(lst);
		lst = lst->next;
		new = start;
		while (lst)
		{
			new->next = f(lst);
			new = new->next;
			lst = lst->next;
		}
		return (start);
	}
	return (NULL);
}
