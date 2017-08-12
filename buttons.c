/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:00:49 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/13 19:23:44 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			rotation_buttons(int keycode, t_fdf *fdf)
{
	if (fdf)
	{
		if (keycode == 16)
			B += 10;
		if (keycode == 22)
			B -= 10;
		if (keycode == 7)
			A += 10;
		if (keycode == 1)
			A -= 10;
		if (keycode == 6)
			G += 10;
		if (keycode == 0)
			G -= 10;
	}
}

static void			move_buttons(int keycode, t_fdf *fdf)
{
	if (keycode == 126 && fdf->pos_y > -320)
		fdf->pos_y -= 10;
	if (keycode == 125 && fdf->pos_y < 1520)
		fdf->pos_y += 10;
	if (keycode == 123 && fdf->pos_x > -270)
		fdf->pos_x -= 10;
	if (keycode == 124 && fdf->pos_x < 1260)
		fdf->pos_x += 10;
}

static void			zoom_buttons(int keycode, t_fdf *fdf)
{
	if (keycode == 78 && fdf->zoom > 0.25)
		fdf->zoom -= 0.25;
	if (keycode == 69 && fdf->zoom < 40)
		fdf->zoom += 0.25;
	if (keycode == 116 && fdf->zoom_z < 100)
		fdf->zoom_z += 1;
	if (keycode == 121 && fdf->zoom_z > -100)
		fdf->zoom_z -= 1;
}

void				buttons(int keycode, t_fdf *fdf)
{
	rotation_buttons(keycode, fdf);
	move_buttons(keycode, fdf);
	zoom_buttons(keycode, fdf);
	color_buttons(keycode, fdf);
	put_image(fdf);
	if (keycode == 53)
		exit(0);
}

void				put_image(t_fdf *fdf)
{
	int				bpss;
	int				endian;

	mlx_destroy_image(fdf->mlx, fdf->im);
	fdf->im = mlx_new_image(fdf->mlx, 1000, 1000);
	fdf->imdat = (int *)mlx_get_data_addr(fdf->im, &bpss, &fdf->ls, &endian);
	foreachpoint(fdf, calc);
	foreachpoint(fdf, check_point);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->im, 0, 0);
}
