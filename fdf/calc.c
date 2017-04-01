/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:08:49 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/15 19:30:41 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			calc(t_point *point, t_fdf *fdf)
{
	if (fdf && point)
	{
//		p->x_screen = p->x_r - p->z_r*0.5 * cos(AA * RAD) + fdf->pos_x;
//		p->y_screen = p->y_r + p->z_r*0.5 * sin(AA * RAD) + fdf->pos_y;
        point->x_screen = (XR * cos(B * RAD) + (ZR * cos(A * RAD) - YR * sin(A *RAD))*sin(B * RAD)) * cos(G* RAD) + (YR*cos(A* RAD) + ZR * sin(A* RAD)) * sin(G* RAD) + fdf->pos_x;
        point->y_screen = -(XR*cos(B* RAD) + (ZR*cos(A* RAD) - YR*sin(A* RAD))*sin(B* RAD))*sin(G* RAD)+ (YR*cos(A* RAD) + ZR*sin(A* RAD))*cos(G* RAD) + fdf->pos_y;
	}
}
//tmp->x = (((x1 * cosB + (-y1 * sinA + z1 * cosA) * sinB) * cosG + (y1 * cosA + z1 * sinA) * sinG + 700) + var->sdvigx);
//tmp->y = ((-(x1 * cosB + (-y1 * sinA + z1 * cosA) * sinB) * sinG + (y1 * cosA + z1 * sinA) * cosG + 700) + var->sdvigy);
