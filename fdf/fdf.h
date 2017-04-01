/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:53:12 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/15 19:19:06 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define X point->x
# define Y point->y
# define Z point->z
# define XR point->x_r
# define YR point->y_r
# define ZR point->z_r
# define COLOR point->color
# define NEXT point->next
# define DOWN point->down
# define AA atan(2)
# define RAD 3.14166667/180
# define A fdf->alpha
# define B fdf->beta
# define G fdf->gamma
# define OTHER  fdf->imdat, fdf->ls, line.p1->color

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
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
    double           x_r;
    double            y_r;
    double              z_r;
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
	int				*imdat;
	int					ls;
	double				alpha;
	double				beta;
	double				gamma;
    int                 pos_x;
    int                 pos_y;
	t_row				*list;
}						t_fdf;

typedef struct          s_line
{
    t_point             *p0;
    t_point             *p1;
	double 					x0;
	double 					y0;
	double 					x1;
	double 					y1;
}                       t_line;

t_row					*new_row(int y);
void					add_row(t_row *first, t_row *row);
t_point					*new_point(int x, int y);
void					add_point(t_point *first, t_point *point);
void					create(t_fdf *fdf);
void					put_line(t_fdf *fdf, t_line line);
void            		foreachpoint(t_fdf *fdf, void (*f)(t_point *, t_fdf *));
void					calculate(t_point *point, t_fdf *fdf);
t_row					*fill_down(t_row *first);
void					put_line1(char *imdat, int ls, t_point *p1, t_point *p2);
void					put_line2(char *imdat, int ls, t_point *p1, t_point *p2);
void					put_pixel(double x, double y, int *idat, int ls, int color);
void 					zoom(t_point *point, t_fdf *fdf);
void					print_map(t_point *point, t_fdf *fdf);
void                 calc(t_point *p, t_fdf *fdf);
void        rotation(int keycode, t_fdf *fdf);
void        rotation_x(t_point *point, t_fdf *fdf);
void        rotation_y(t_point *point, t_fdf *fdf);
void        rotation_z(t_point *point, t_fdf *fdf);
void        put_im(t_fdf *fdf);
int	                   move(int keycode, t_fdf *fdf);
//void        overturn(t_point *point, t_fdf *fdf);
#endif