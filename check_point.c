/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:17:04 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/12 20:15:41 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_line(t_line *line)
{
	(*line).x0 = (*line).p0->x_screen;
	(*line).y0 = (*line).p0->y_screen;
	(*line).x1 = (*line).p1->x_screen;
	(*line).y1 = (*line).p1->y_screen;
}

void			check_point(t_point *point, t_fdf *fdf)
{
	t_line		line;

	line.p0 = point;
	line.x0 = point->x_screen;
	line.y0 = point->y_screen;
	if (point->next)
	{
		line.p0 = (Z < point->next->z) ? point : point->next;
		line.p1 = (Z < point->next->z) ? point->next : point;
		fill_line(&line);
		put_line(fdf, line);
	}
	if (point->down)
	{
		line.p0 = (Z < point->down->z) ? point : point->down;
		line.p1 = (Z < point->down->z) ? point->down : point;
		fill_line(&line);
		put_line(fdf, line);
	}
	else if (!point->down && !point->next && Y == 0 && X == 0)
	{
		put_pixel(500, 500, fdf, 0xFFFFFF);
	}
}
