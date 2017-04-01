/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:44:05 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/15 16:44:51 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void		    calculate(t_point *point, t_fdf *fdf)
{
    t_line      line;
	/* write(1, "calculate_start\n", 16); */
	// if (list)
		// printf("x : %d, y %d\n", point->x, point->y);
//    line = (t_line)malloc(sizeof(t_line));
    line.p0 = point;
    line.x0 = point->x_screen;
    line.y0 = point->y_screen;
	if (point->next)
	{
//		printf("NEXT[x1 %d, y1 %d, x2 %d, y2 %d\n", point->x, point->y, point->next->x, point->next->y);
		// write(1, "calc\n", 5);
        line.p1 = point->next;
        line.x1 = line.p1->x_screen;
        line.y1 = line.p1->y_screen;
		put_line(fdf, line);
//		printf("NEXT_END\n");
		
	}
	if (point->down)
	{
        line.p1 = point->down;
        line.x1 = line.p1->x_screen;
        line.y1 = line.p1->y_screen;
//		printf("DOWN[x1 %d, y1 %d, x2 %d, y2 %d\n", point->x, point->y, point->down->x, point->down->y);
		put_line(fdf, line);
//		printf("DOWN_END\n");

	}
	/* write(1, "calculate_end\n", 14); */
}
