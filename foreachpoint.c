/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreachpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:28:59 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/12 14:32:29 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			foreachpoint(t_fdf *fdf, void (*f)(t_point *, t_fdf *))
{
	t_row		*row;
	t_point		*point;

	row = fdf->list->next;
	while (row)
	{
		point = row->point->next;
		while (point)
		{
			if (point)
				(*f)(point, fdf);
			point = point->next;
		}
		row = row->next;
	}
}
