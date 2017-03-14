/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:07:09 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 19:08:53 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*fresh_mem;
	size_t			i;

	i = 0;
	fresh_mem = (unsigned char *)malloc(size);
	if (fresh_mem)
	{
		while (size > 0)
		{
			fresh_mem[i] = '\0';
			i++;
			size--;
		}
		return (fresh_mem);
	}
	else
		return (NULL);
}
