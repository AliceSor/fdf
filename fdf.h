/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:48:21 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/13 18:58:46 by asoroka          ###   ########.fr       */
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
# define OTHER  fdf, line.color
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	double				x_r;
	double				y_r;
	double				z_r;
	double				x_screen;
	double				y_screen;
	int					color;
	struct s_point		*next;
	struct s_point		*down;
	int					r;
	int					g;
	int					b;
}						t_point;

typedef struct			s_row
{
	t_point				*point;
	int					y;
	struct s_row		*next;
}						t_row;

typedef struct			s_fdf
{
	void				*win;
	void				*mlx;
	void				*im;
	int					*imdat;
	int					ls;
	double				alpha;
	double				beta;
	double				gamma;
	int					pos_x;
	int					pos_y;
	t_row				*list;
	int					max_x;
	int					max_y;
	int					max_z;
	double				zoom;
	double				zoom_z;
	int					color_coef;
	int					flaf_r;
	int					flag_r;
	int					flag_g;
	int					flag_b;
}						t_fdf;

typedef struct			s_line
{
	t_point				*p0;
	t_point				*p1;
	double				x0;
	double				y0;
	double				x1;
	double				y1;
	int					x;
	int					y;
	int					i;
	int					color;
	int					d;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					r;
	int					g;
	int					b;
}						t_line;

t_row					*new_row(int y);
void					add_row(t_row *first, t_row *row);
t_point					*new_point(int x, int y);
void					add_point(t_point *first, t_point *point);
void					create(t_fdf *fdf);
void					put_line(t_fdf *fdf, t_line line);
void					foreachpoint(t_fdf *fdf, void (*f)(t_point *, t_fdf *));
void					check_point(t_point *point, t_fdf *fdf);
t_row					*fill_down(t_row *first);
void					put_line1(t_fdf *fdf, t_line line);
void					put_line2(t_fdf *fdf, t_line line);
void					put_pixel(double x, double y, t_fdf *fdf, int color);
void					zoom(t_point *point, t_fdf *fdf);
void					calc(t_point *p, t_fdf *fdf);
void					buttons(int keycode, t_fdf *fdf);
void					put_image(t_fdf *fdf);
void					find_max(t_fdf *fdf);
void					find_max_z(t_point *point, t_fdf *fdf);
void					reduce_z(t_point *point, t_fdf *fdf);
void					increase_z(t_point *point, t_fdf *fdf);
void					colorise(t_point *point, t_fdf *fdf);
void					color_buttons(int keycode, t_fdf *fdf);

#endif
