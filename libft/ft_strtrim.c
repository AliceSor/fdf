/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:56:24 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 19:09:30 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*newstr;
	size_t		st;
	size_t		e;

	st = 0;
	if (s)
	{
		e = ft_strlen(s) - 1;
		while (s[st] && (s[st] == ' ' || s[st] == '\n' || s[st] == '\t'))
			st++;
		while (e > 0 && (s[e] == ' ' || s[e] == '\n' || s[e] == '\t'))
			e--;
		if (e > st)
		{
			if ((newstr = ft_strsub(s, st, e - st + 1)) == 0)
				return (NULL);
		}
		else
		{
			if ((newstr = ft_strdup("")) == 0)
				return (NULL);
		}
		return (newstr);
	}
	return (NULL);
}
