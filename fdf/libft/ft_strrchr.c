/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:26:26 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 19:36:58 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*ss;

	ss = (char *)s;
	len = ft_strlen(ss) + 1;
	while (--len + 1 >= 1)
		if (ss[len] == (char)c)
			return (ss + len);
	if ((char)c == '\0')
		return (ss);
	return (NULL);
}
