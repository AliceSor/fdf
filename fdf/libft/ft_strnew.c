/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:43:06 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/01 19:49:36 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*fresh_str;

	fresh_str = (char *)malloc((size + 1) * sizeof(char));
	if (fresh_str)
	{
		ft_bzero(fresh_str, size + 1);
		return (fresh_str);
	}
	return (NULL);
}
