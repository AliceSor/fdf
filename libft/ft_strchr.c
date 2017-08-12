/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:05:36 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 19:53:18 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ss;

	ss = (char *)s;
	while (*ss)
	{
		if (*ss == (char)c)
			return (ss);
		ss++;
	}
	if ((char)c == '\0')
		return (ss);
	return (NULL);
}
