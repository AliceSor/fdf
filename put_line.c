/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:15:14 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/12 17:57:23 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_line1(t_fdf *fdf, t_line line)
{
	int			d1;
	int			d2;

	line.d = (line.dy << 1) - line.dx;
	d1 = line.dy << 1;
	d2 = (line.dy - line.dx) << 1;
	line.x = (int)(line.x0 + line.sx);
	line.y = (int)line.y0;
	while (line.i <= line.dx)
	{
		if (line.d > 0)
		{
			line.d += d2;
			line.y += line.sy;
		}
		else
			line.d += d1;
		line.b -= (1 - fdf->flag_b) * 0.0000000000001;
		line.g -= (1 - fdf->flag_g) * 0.0000000000001;
		line.r -= (1 - fdf->flag_r) * 0.0000000000001;
		line.color = (line.r << 16) + (line.g << 8) + (line.b);
		put_pixel(line.x, line.y, fdf, line.color);
		line.i++;
		line.x += line.sx;
	}
}

void			put_line2(t_fdf *fdf, t_line line)
{
	int			d1;
	int			d2;

	line.d = (line.dx << 1) - line.dy;
	d1 = line.dx << 1;
	d2 = (line.dx - line.dy) << 1;
	line.y = (int)(line.y0 + line.sy);
	line.x = (int)line.x0;
	while (line.i <= line.dy)
	{
		if (line.d > 0)
		{
			line.d += d2;
			line.x += line.sx;
		}
		else
			line.d += d1;
		line.b -= (1 - fdf->flag_b) * 0.0000000000001;
		line.g -= (1 - fdf->flag_g) * 0.0000000000001;
		line.r -= (1 - fdf->flag_r) * 0.0000000000001;
		line.color = (line.r << 16) + (line.g << 8) + (line.b);
		put_pixel(line.x, line.y, OTHER);
		line.i++;
		line.y += line.sy;
	}
}

void			put_line(t_fdf *fdf, t_line line)
{
	line.r = line.p0->r;
	line.g = line.p0->g;
	line.b = line.p0->b;
	line.dx = abs((int)(line.x1 - line.x0));
	line.dy = abs((int)(line.y1 - line.y0));
	line.sx = line.x1 >= line.x0 ? 1 : -1;
	line.sy = line.y1 >= line.y0 ? 1 : -1;
	line.i = 1;
	if (line.dy <= line.dx)
		put_line1(fdf, line);
	else
		put_line2(fdf, line);
}
