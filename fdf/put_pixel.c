/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:23:07 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/12 16:23:10 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(int *idat, int x, int y, int ls, int color)
{
	int			i;

	// color = 16777215;
	// printf("put_pixel[x %d, y %d, ls %d, idat %s]\n", x, y, ls, (char *)idat);
	i = ls*(y)/4 + x;
	// i *= 10;
	if (i < 1000000 - 2)
		idat[i] = color;
}