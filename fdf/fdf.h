/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:53:12 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/06 19:49:20 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define X row->point->x
# define Y row->point->y
# define Z row->point->z
# define COLOR row->point->color
# define NEXT row->point->next;
# define DOWN row->point->down;

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
///////
#include <stdio.h>
///////

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	double				x_screen;
	double				y_screen;
	int					color;
	struct s_point		*next;
	struct s_point		*down;
}						t_point;

typedef struct			s_row
{
	t_point				*point;
	int					y;
	struct s_row		*next;
}						t_row;

typedef struct 			s_fdf
{
	void				*win;
	void				*mlx;
	void				*im;
	char				*imdat;
	int					ls;
	t_row				*list;
}						t_fdf;

t_row					*new_row(int y);
void					add_row(t_row *first, t_row *row);
t_point					*new_point(int x, int y);
void					add_point(t_point *first, t_point *point);
void					create(t_fdf *fdf);
void					put_line(char *imdat, int ls, t_point *p1, t_point *p2);
void            		foreachpoint(t_fdf *fdf, void (*f)(t_point *, t_fdf *));
void					calculate(t_point *point, t_fdf *fdf);
t_row					*fill_down(t_row *first);
void					put_line1(char *imdat, int ls, t_point *p1, t_point *p2);
void					put_line2(char *imdat, int ls, t_point *p1, t_point *p2);
void					put_pixel(int *idat, int x, int y, int ls, int color);
void 					zoom(t_point *point, t_fdf *fdf);

#endif