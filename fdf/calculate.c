/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:44:05 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/07 19:48:42 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void		calculate(t_point *point, t_fdf *fdf)
{
	write(1, "calculate_start\n", 16);
	// if (list)
		// printf("x : %d, y %d\n", point->x, point->y);
	if (point->next)
	{
		printf("NEXT[x1 %d, y1 %d, x2 %d, y2 %d\n", point->x, point->y, point->next->x, point->next->y);
		// write(1, "calc\n", 5);
		put_line(fdf->imdat, fdf->ls, point, point->next);
		
	}
	if (point->down)
	{
		printf("DOWN[x1 %d, y1 %d, x2 %d, y2 %d\n", point->x, point->y, point->down->x, point->down->y);
		put_line(fdf->imdat, fdf->ls, point, point->down);
		
	}
	write(1, "calculate_end\n", 14);
}
