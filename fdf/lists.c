/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:10:26 by asoroka           #+#    #+#             */
/*   Updated: 2017/02/27 19:23:04 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_row			*new_row(int y)
{
	t_row		*new_row;

	new_row = (t_row *)malloc(sizeof(t_row) + 1);
	if (new_row)
	{
		new_row->y = y;
		new_row->point = NULL;
		new_row->next = NULL;
	}
	return (new_row);
}

void			add_row(t_row *first, t_row *row)
{
	t_row		*i;

	i = first;
	while (i->next)
		i = i->next;
	i->next = row;
}

t_point			*new_point(int x, int y)
{
	t_point		*new_point;

	new_point = (t_point *)malloc(sizeof(t_point) + 1);
	if (new_point)
	{
		new_point->x = x;
		new_point->y = y;
		new_point->color = 0;
		new_point->next = NULL;
		new_point->down = NULL;
	}
	return (new_point);
}

void			add_point(t_point *first, t_point *point)
{
	t_point		*i;

	i = first;
	while (i->next)
		i = i->next;
	i->next = point;
}
