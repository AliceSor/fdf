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

	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, "test");
	fdf->im = mlx_new_image(fdf->mlx, 1000, 1000);
	fdf->imdat = mlx_get_data_addr(fdf->im, &bpss, &fdf->ls, &endian);

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
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->im, 0, 0);

	mlx_hook(fdf->win, 2, 5, rotation, fdf);

	mlx_key_hook(fdf->win, key_hook, 0);
	mlx_loop(fdf->mlx);
}
