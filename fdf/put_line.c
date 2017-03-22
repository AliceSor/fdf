/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:33:27 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/06 19:49:15 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

void		put_line(char *imdat, int ls, t_point *p1, t_point *p2)
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	// printf("put_line[x1 = %d, y1 = %d, x2 = %d, y2 = %d]\n", p1->x_screen, p1->y_screen, p2->x_screen, p2->y_screen);
	if (p1->y_screen == p2->y_screen)
	{
		x1 = p1->x_screen;
		x2 = p2->x_screen;
		if (p1->x_screen > p2->x_screen)
		{
			x1 = x2;
			x2 = p1->x_screen;
		}
		while (x1 <= x2)
			put_pixel((int *)imdat, x1++, p1->y_screen, ls, p2->color);
	}
	else if(p1->x_screen == p2->x_screen)
	{
		y1 = p1->y_screen;
		y2 = p2->y_screen;
		if (p1->y_screen > p2->y_screen)
		{
			y1 = p2->y_screen;
			y2 = p1->y_screen;
		}
		while (y1 <= y2)
			put_pixel((int *)imdat, p1->x_screen, y1++, ls, p2->color);
	}
	else if((p2->x_screen > p1->x_screen && p2->y_screen > p1->y_screen) || (p1->x_screen > p2->x_screen && p1->y_screen > p2->y_screen))
		put_line1(imdat, ls, p1, p2);
	else if( p2->x_screen < p1->x_screen || p2->y_screen < p1->y_screen)
		put_line2(imdat, ls, p1, p2);
}