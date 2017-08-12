/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:46:42 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 17:56:26 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;

	b = ft_strstr(big, little);
	if ((b - big) + ft_strlen(little) > len)
		return (NULL);
	return (b);
}
