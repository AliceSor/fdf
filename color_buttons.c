/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_buttons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:11:31 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/12 20:29:31 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_red(t_fdf *fdf)
{
	if (fdf->flag_r == 0)
	{
		fdf->flag_r = 1;
		fdf->flag_g = 0;
		fdf->flag_b = 0;
	}
	foreachpoint(fdf, colorise);
}

static void		set_green(t_fdf *fdf)
{
	if (fdf->flag_g == 0)
	{
		fdf->flag_r = 0;
		fdf->flag_g = 1;
		fdf->flag_b = 0;
	}
	foreachpoint(fdf, colorise);
}

static void		set_blue(t_fdf *fdf)
{
	if (fdf->flag_b == 0)
	{
		fdf->flag_r = 0;
		fdf->flag_g = 0;
		fdf->flag_b = 1;
	}
	foreachpoint(fdf, colorise);
}

void			color_buttons(int keycode, t_fdf *fdf)
{
	if (keycode == 10)
	{
		fdf->color_coef = (fdf->color_coef < 100) ? fdf->color_coef + 1 : 0;
		foreachpoint(fdf, colorise);
	}
	if (keycode == 15)
	{
		set_red(fdf);
	}
	if (keycode == 5)
	{
		set_green(fdf);
	}
	if (keycode == 11)
	{
		set_blue(fdf);
	}
}
