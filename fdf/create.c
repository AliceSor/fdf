/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:21:59 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/15 19:22:04 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define X row->point->x
#define Y row->point->y
#define Z row->point->z
static int				key_hook(int kc)
{
	if (kc == 53)
		exit(0);
	return (0);
}

void			create(t_fdf *fdf)
{
	int			bpss;
	int			endian;
	/* t_point		*p1; */
	/* t_point		*p2; */
	// char		*imdat;

	void		*mlx;
	void		*im;
	void		*win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "test");
	im = mlx_new_image(mlx, 1000, 1000);
	fdf->imdat = mlx_get_data_addr(im, &bpss, &fdf->ls, &endian);

	write(1, "11\n", 3);

	/* p1 = new_point(500, 500); */
	/* p2 = new_point(0, 999); */
	/* p1->color = 0x0000FF; */
	/* p2->color = 0x0000FF; */
	/* put_line(fdf->imdat, fdf->ls, p1, p2); */

	foreachpoint(fdf, zoom);
	foreachpoint(fdf, print_map);
	foreachpoint(fdf, calc);
	foreachpoint(fdf, calculate);
	write(1, "22\n", 3);
	mlx_put_image_to_window(mlx, win, im, 0, 0);
	write(1, "OK\n", 3);
	mlx_key_hook(win, key_hook, 0);
	mlx_loop(mlx);
}
