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
    if (fdf)
    {
        if (keycode == 16)
        {
            B +=4;
//            foreachpoint(fdf, rotation_y);
        }
        if (keycode == 7)
        {
            A += 4;
//            foreachpoint(fdf, rotation_x);
        }
        if (keycode == 6)
        {
            G += 4;
            printf("G %f\n", G);
//            if (G >= 180)
//                G = 0;
//            foreachpoint(fdf, rotation_z);
        }
        if (keycode == 0)
        {
            G -= 4;
            printf("G %f\n", G);
            if (G >= 45)
                G = 0;
//            foreachpoint(fdf, rotation_z);
        }
        put_im(fdf);
    }
}

//void        rotation_x(t_point *point, t_fdf *fdf)
//{
//    if (fdf && point)
//    {
////        printf("\n\nHHH\n\n");
//        point->y_r = Y * cos(A * RAD) + Z * sin(B * RAD);
//        point->z_r = -Y * sin(A * RAD) + Z * cos(B * RAD);
//    }
//}
//
//void        rotation_y(t_point *point, t_fdf *fdf)
//{
//    if (fdf && point)
//    {
//        point->x_r = X * cos(B * RAD) - Z * sin(B * RAD);
//        point->z_r = X * sin(B * RAD) + Z * cos(B * RAD);
//    }
//}
//
//void        rotation_z(t_point *point, t_fdf *fdf)
//{
//    if (fdf && point)
//    {
//        point->x_r = X * cos(G * RAD) + Y * sin(G * RAD);
//        point->y_r = -X * sin(G * RAD) + Y * cos(G * RAD);
//    }
//}

void        put_im(t_fdf *fdf)
{
    int			bpss;
    int			endian;

    mlx_destroy_image (fdf->mlx, fdf->im);
    fdf->im = mlx_new_image(fdf->mlx, 1000, 1000);
    fdf->imdat = (int *)mlx_get_data_addr(fdf->im, &bpss, &fdf->ls, &endian);
    foreachpoint(fdf, calc);
    foreachpoint(fdf, calculate);
    mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->im, 0, 0);
}

//void        overturn(t_point *point, t_fdf *fdf)
//{
//    if (fdf && point)
//    {
//        if (A > 45)
//        {
//            Z = -Z;
//        }
//    }
//}