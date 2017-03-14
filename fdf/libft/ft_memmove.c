/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:11:46 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/07 14:05:50 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*buff;
	size_t			i;

	i = 0;
	buff = (unsigned char *)malloc(len * sizeof(unsigned char));
	if (buff)
	{
		while (i < len)
		{
			buff[i] = ((unsigned char *)src)[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			((unsigned char *)dest)[i] = buff[i];
			i++;
		}
	}
	free(buff);
	return (dest);
}
