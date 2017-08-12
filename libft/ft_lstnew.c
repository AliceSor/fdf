/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:51:26 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/09 21:04:12 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;
	void		*cont;

	if (content)
		cont = (void *)malloc(content_size * sizeof(void));
	else
	{
		content_size = 0;
		cont = NULL;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->content = ft_memcpy(cont, (void *)content, content_size);
		new->content_size = content_size;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
