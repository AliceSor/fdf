/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:39:59 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/22 16:40:03 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        rotation(int keycode, t_fdf *fdf)
{
    int			bpss;
    int			endian;

    if (fdf)
    {
        if (keycode == 7)
        {
            if (A > 45)
            {
                printf("\n\nHHH\n\n");
                A = 0;
                exit(0);
            }
            A++;
            foreachpoint(fdf, rotation_x);
        }
        mlx_destroy_image (fdf->mlx, fdf->im);
        fdf->im = mlx_new_image(fdf->mlx, 1000, 1000);
        fdf->imdat = mlx_get_data_addr(fdf->im, &bpss, &fdf->ls, &endian);
        foreachpoint(fdf, calc);
        foreachpoint(fdf, calculate);
        mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->im, 0, 0);
    }
}

void        rotation_x(t_point *point, t_fdf *fdf)
{
    if (fdf && point)
    {
//        printf("\n\nHHH\n\n");
        Y = (int) (Y * cos(A * RAD) + Z * sin(B * RAD));
        Z = (int) (-Y * sin(A * RAD) + Z * cos(B * RAD));
    }
}

//void        rotation_y(t_point *point, t_fdf *fdf)
//{
//    if (fdf && point)
//    {
//        B++;
//        X = X * cos(B * RAD) - Z * sin(B * RAD);
//        Z = X * sin(B * RAD) + Z * cos(B * RAD);
//    }
//}
//
//void        rotation_z(t_point *point, t_fdf *fdf)
//{
//    if (fdf && point)
//    {
//        G++;
//        X = X * cos(G * RAD) + Y * sin(G * RAD);
//        Y = -X * sin(G * RAD) + Y * cos(G * RAD);
//    }
//}