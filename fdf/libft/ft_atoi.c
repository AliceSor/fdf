/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:35:46 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 19:08:42 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int		res;
	int		negative;
	size_t	i;

	negative = 1;
	res = 0;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if ((s[i] == '-') || (s[i] == '+'))
	{
		if (s[i] == '-')
			negative = -1;
		i++;
	}
	while (ft_isdigit(s[i]) == 1)
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (negative * res);
}
