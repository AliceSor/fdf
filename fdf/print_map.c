/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:53:57 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/15 16:57:19 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			print_map(t_point *point, t_fdf *fdf)
{
	if (fdf && point)
		printf("(%d, %d)\n", point->x, point->y);
}
