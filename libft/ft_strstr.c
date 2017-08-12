/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:26:30 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 19:06:08 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char			*ft_strstr(const char *str, const char *to_find)
{
	size_t			len;
	char			*begin;
	size_t			i;

	i = 0;
	len = ft_strlen((const char *)to_find);
	if (*to_find == '\0')
		return ((char *)str);
	while (*str)
	{
		i = ft_strncmp(str, to_find, len);
		begin = (char *)str;
		if (i != 0)
			str++;
		else
			return (begin);
	}
	return (NULL);
}
