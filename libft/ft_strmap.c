/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:19:53 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 19:02:38 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh_str;
	int		len;
	size_t	i;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		fresh_str = (char *)malloc((len + 1) * sizeof(char));
		if (fresh_str)
		{
			while (s[i])
			{
				fresh_str[i] = f((char)s[i]);
				i++;
			}
			fresh_str[i] = '\0';
			return (fresh_str);
		}
	}
	return (NULL);
}
