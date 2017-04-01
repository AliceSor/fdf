/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:33:27 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/01 20:32:41 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

void 	put_line(t_fdf *fdf, t_line line)
//        void segment(int x0, int y0, int x1, int y1, int color)
{
    int dx = abs((int) (line.x1 - line.x0));
    int dy = abs((int) (line.y1 - line.y0));
    int sx = line.x1 >= line.x0 ? 1 : -1;
    int sy = line.y1 >= line.y0 ? 1 : -1;
    int d;
    int d1;
    int d2;
    int x;
    int y;
    int i;

    if (line.y0 == line.y1)
        printf("kjdfbdsjkbvjklb");
    if (dy <= dx)
    {
        d = (dy << 1) - dx;
        d1 = dy << 1;
        d2 = (dy - dx) << 1;
//        put_pixel(line.x0, line.y0, OTHER);
        for(x = (int) (line.x0 + sx), y = (int) line.y0, i = 1; i <= dx; i++, x += sx)
        {
            if ( d >0)
            {
                d += d2;
                y += sy;
            }
            else
                d += d1;
            put_pixel(x, y, OTHER);
        }
    }
    else
    {
        d = (dx << 1) - dy;
        d1 = dx << 1;
        d2 = (dx - dy) << 1;
//        put_pixel(line.x0, line.y0, OTHER);
        for(y = (int) (line.y0 + sy), x = (int) line.x0, i = 1; i <= dy; i++, y += sy)
        {
            if ( d >0)
            {
                d += d2;
                x += sx;
            }
            else
                d += d1;
            put_pixel(x, y, OTHER);
        }
    }
}
