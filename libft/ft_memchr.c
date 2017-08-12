/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:30:44 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 18:49:59 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	unsigned char		*s2;

	s1 = s;
	while (n--)
	{
		if (*s1 == (unsigned char)c)
		{
			s2 = (unsigned char *)s1;
			return (s2);
		}
		s1++;
	}
	return (NULL);
}
