/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:28:30 by asoroka           #+#    #+#             */
/*   Updated: 2017/02/22 18:43:34 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	size_t		i;
	char		*new;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(new = (char*)malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	i = -1;
	while (++i < len_s1)
		new[i] = s1[i];
	len_s1 = -1;
	while (++len_s1 < len_s2)
		new[i++] = s2[len_s1];
	new[i] = '\0';
	return (new);
}
