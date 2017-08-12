/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:34:44 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/13 19:23:25 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					find_max(t_fdf *fdf)
{
	t_row				*row;
	t_point				*point;

	row = fdf->list->next;
	fdf->max_y = 1;
	fdf->max_x = 1;
	while (row->next)
	{
		point = row->point->next;
		while (point->next)
		{
			point = point->next;
		}
		if (point->x > fdf->max_x)
			fdf->max_x = point->x;
		row = row->next;
	}
	fdf->max_y = (row->y) ? row->y : 1;
	fdf->max_z = 1;
	foreachpoint(fdf, find_max_z);
}

void					find_max_z(t_point *point, t_fdf *fdf)
{
	if (Z > fdf->max_z)
		fdf->max_z = Z;
}

void					colorise(t_point *point, t_fdf *fdf)
{
	if (point && fdf)
	{
		point->r = 255 - fdf->color_coef * abs(Z) * (1 - fdf->flag_r);
		point->b = 255 - fdf->color_coef * abs(Z) * (1 - fdf->flag_g);
		point->g = 255 - fdf->color_coef * abs(Z) * (1 - fdf->flag_b);
	}
}

int						destroy(void)
{
	exit(1);
}

void					create(t_fdf *fdf)
{
	int					bpss;
	int					endian;

	find_max(fdf);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, "test");
	fdf->im = mlx_new_image(fdf->mlx, 1000, 1000);
	fdf->imdat = (int *)mlx_get_data_addr(fdf->im, &bpss, &fdf->ls, &endian);
	foreachpoint(fdf, colorise);
	foreachpoint(fdf, zoom);
	foreachpoint(fdf, calc);
	foreachpoint(fdf, check_point);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->im, 0, 0);
	mlx_hook(fdf->win, 2, 5, (int (*)()) buttons, fdf);
	mlx_hook(fdf->win, 17, 0, destroy, 0);
	mlx_loop(fdf->mlx);
}
