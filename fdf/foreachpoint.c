/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreachpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 19:01:28 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/15 16:42:31 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void            foreachpoint(t_fdf *fdf, void (*f)(t_point *, t_fdf *))
{
    
    t_row       *row;
    t_point     *point;
    row = fdf->list->next;
    /* write(1, "FEP_S\n", 6); */
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
    /* write(1, "FEP_E\n", 6); */
}
