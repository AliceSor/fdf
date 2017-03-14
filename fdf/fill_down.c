/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:36:24 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/10 16:36:27 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*find_down(t_point *point, t_point *to_find)
{
	t_point		*p;

	p = to_find->next;
	while (p)
	{
		if (p->x == point->x)
		{
			return (p);
		}
		p = p->next;
	}
	return (NULL);
}

t_row	*fill_down(t_row *first)
{
	t_row		*row;
	t_point		*down;
	t_point		*p;

	row = first;
	row = row->next;
	while (row->next)
	{
		p = row->point->next;
		while (p)
		{
			if (row->next)
				down = find_down(p, row->next->point);
			p->down = down;
			p = p->next;
		}
		row = row->next;
	}
	return (first);
}