/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:16:54 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/12 16:17:01 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_line2(char *imdat, int ls, t_point *p1, t_point *p2)
{
	printf("put_line2\n");
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	double	dx;
	double	dy;
	double	error;
	double	derror;
	int		t;

	x1 = p1->x_screen;
	y1 = p1->y_screen;
	x2 = p2->x_screen;
	y2 = p2->y_screen;
	if (x1 > x2)
	{
		t = x1;
		x1 = x2;
		x2 = t;
		t = y1;
		y1 = y2;
		y2 = t;		
	}
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
			y1--;
		}
		else
			error += 2 * derror;
		x1 += 1;
	}
}
