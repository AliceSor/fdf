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

// void		put_line(char *imdat, int x1, int x2, int y1, int y2, int color, int ls, int len)
// {
// 	int		*idat;
// 	int		i;

// 	idat = (int *)imdat;
// 	i = (int)sqrt((int)(x2-x1)*(x2-x1) + (int)(y2-y1)*(y2-y1));
// 	if (len > 0)
// 	{
// 		len--;
// 		put_pixel(idat, (x2+x1)/2, (y2 + y1)/2, ls, color);
// 		printf ("len :%d\n", len);
// 		put_line(imdat, x1, (x2 + x1)/2, y1, (y1 + y2) / 2, color, ls, --len);
// 		put_line(imdat, (x2 + x1)/2, x2, (y1 + y2)/ 2, y2, color, ls, --len); 
// 	}
// }

// static void		swap(double *i1, double *i2)
// {
// 	double		temp;

// 	temp = *i1;
// 	*i1 = *i2;
// 	*i2 = temp;
// }


void		put_line(char *imdat, int ls, t_point *p1, t_point *p2)
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	printf("put_line[x1 = %d, y1 = %d, x2 = %d, y2 = %d]\n", p1->x, p1->y, p2->x, p2->y);
	if (p1->y == p2->y)
	{
		x1 = p1->x;
		x2 = p2->x;
		if (p1->x > p2->x)
		{
			x1 = x2;
			x2 = p1->x;
		}
		while (x1 <= x2)
			put_pixel((int *)imdat, x1++, p1->y, ls, p1->color);
	}
	else if(p1->x == p2->x)
	{
		y1 = p1->y;
		y2 = p2->y;
		if (p1->y > p2->y)
		{
			y1 = p2->y;
			y2 = p1->y;
		}
		while (y1 <= y2)
			put_pixel((int *)imdat, p1->x, y1++, ls, p1->color);
	}
	else if((p2->x > p1->x && p2->y > p1->y) || (p1->x > p2->x && p1->y > p2->y))
		put_line1(imdat, ls, p1, p2);
	else if( p2->x < p1->x || p2->y < p1->y)
		put_line2(imdat, ls, p1, p2);
}