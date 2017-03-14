/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:08:52 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/08 20:55:56 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;
	t_list		*victrim;

	if (alst && del)
	{
		list = *alst;
		while (list)
		{
			victrim = list;
			del(victrim->content, victrim->content_size);
			free(victrim);
			list = list->next;
		}
		*alst = NULL;
	}
}
