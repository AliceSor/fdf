/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:54:35 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 19:09:02 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memccpy(void *dest, const void *src,\
		int c, size_t n)
{
	unsigned char		*dest1;
	const unsigned char	*src1;
	size_t				i;

	dest1 = (unsigned char *)dest;
	src1 = (const unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		if (src1[i] == (unsigned char)c)
		{
			dest1[i] = (unsigned char)c;
			return ((unsigned char *)dest + i + 1);
		}
		dest1[i] = src1[i];
		i++;
		n--;
	}
	return (0);
}
