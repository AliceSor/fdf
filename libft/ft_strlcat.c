/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:31:08 by asoroka           #+#    #+#             */
/*   Updated: 2016/11/28 16:43:13 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*dest1;
	const char		*src1;
	size_t			free_box;
	size_t			dest_len;

	dest1 = dest;
	src1 = src;
	free_box = size;
	while (free_box-- != 0 && *dest1 != '\0')
		dest1++;
	dest_len = dest1 - dest;
	free_box = size - dest_len;
	if (free_box == 0)
		return (dest_len + ft_strlen(src1));
	while (*src1 != '\0')
	{
		if (free_box > 1)
		{
			*dest1++ = *src1;
			free_box--;
		}
		src1++;
	}
	*dest1 = '\0';
	return (dest_len + (src1 - src));
}
