/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:10:37 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/09 21:11:07 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh_str;

	if (s)
	{
		fresh_str = (char *)malloc((len + 1) * sizeof(char));
		if (fresh_str)
		{
			fresh_str = (char *)ft_memcpy(fresh_str, (void *)(s + start), len);
			fresh_str[len] = '\0';
			return (fresh_str);
		}
	}
	return (NULL);
}
