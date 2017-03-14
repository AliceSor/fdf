/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:05:01 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 18:58:51 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *a, const void *b, size_t n)
{
	const unsigned char		*a1;
	const unsigned char		*b1;
	size_t					i;

	a1 = a;
	b1 = b;
	i = -1;
	while (++i < n)
		if (a1[i] - b1[i] != 0)
			return (a1[i] - b1[i]);
	return (0);
}
