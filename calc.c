/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:08:49 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/12 14:57:56 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			calc(t_point *point, t_fdf *fdf)
{
	if (fdf && point)
	{
		point->x_r = X;
		point->y_r = Y;
		point->z_r = Z * (-0.1 * fdf->zoom_z);
		point->x_screen = (XR * cos(B * RAD) + (ZR * cos(A * RAD)\
					- YR * sin(A * RAD)) * sin(B * RAD)) * cos(G * RAD) + (YR\
					* cos(A * RAD) + ZR * sin(A * RAD)) * sin(G * RAD);
		point->y_screen = -(XR * cos(B * RAD) + (ZR * cos(A * RAD)\
					- YR * sin(A * RAD)) * sin(B * RAD)) * sin(G * RAD) + (YR\
					* cos(A * RAD) + ZR * sin(A * RAD)) * cos(G * RAD);
		point->x_screen = point->x_screen * fdf->zoom *\
					(500 / fdf->max_x) + fdf->pos_x;
		point->y_screen = point->y_screen * fdf->zoom *\
					(500 / fdf->max_y) + fdf->pos_y;
	}
}
