/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:16:39 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/12 16:16:44 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_line1(char *imdat, int ls, t_point *p1, t_point *p2)
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	double	dx;
	double	dy;
	double	error;
	double	derror;
	int		t;

	x1 = p1->x;
	y1 = p1->y;
	x2 = p2->x;
	y2 = p2->y;
	if (x1 > x2)
	{
		t = x1;
		x1 = x2;
		x2 = t;
		t = y1;
		y1 = y2;
		y2 = t;		
	}
	printf("\nput_line1[x1 %d | y1 %d | x2 %d | y2 %d\n\n", x1, y1, x2, y2);
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	derror = dy / dx;
	error = 2 * derror - 1;
	while (x1 <= x2)
	{
		put_pixel((int *)imdat, round(x1), round(y1), ls, p1->color);
		if (error > 0)
		{
			error += 2 * derror - 2;
			y1++;
		}
		else
			error += 2 * derror;
		x1 += 1;
	}
}
