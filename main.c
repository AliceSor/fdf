/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:33:35 by asoroka           #+#    #+#             */
/*   Updated: 2017/04/13 19:22:04 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		preferences(t_fdf *fdf)
{
	fdf->alpha = 30;
	fdf->beta = 30;
	fdf->gamma = -25;
	fdf->pos_x = 500;
	fdf->pos_y = 500;
	fdf->zoom = 1;
	fdf->zoom_z = 1;
	fdf->color_coef = 100;
	fdf->flag_r = 1;
	fdf->flag_g = 0;
	fdf->flag_b = 0;
}

static void		fill_row(t_row *row, char *line, t_fdf *fdf)
{
	int			x;
	char		**l;
	t_point		*first_point;
	t_point		*point;
	char		*n;

	x = -1;
	first_point = new_point(x + 1, row->y);
	row->point = first_point;
	l = ft_strsplit(line, ' ');
	if (l)
	{
		while (l[++x])
		{
			point = new_point(x, row->y);
			if ((n = strchr(l[x], ',')))
				*n = '\0';
			point->z = ft_atoi(l[x]);
			point->r = 255 - fdf->color_coef * abs(Z) * (1 - fdf->flag_r);
			point->b = 255 - fdf->color_coef * abs(Z) * (1 - fdf->flag_g);
			point->g = 255 - fdf->color_coef * abs(Z) * (1 - fdf->flag_b);
			add_point(first_point, point);
		}
		free(l);
	}
}

static t_row	*read_map(int fd, t_fdf *fdf)
{
	t_row		*row;
	t_row		*first_row;
	int			y;
	int			ret;
	char		*line;

	y = 0;
	first_row = new_row(y);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		row = new_row(y);
		if (line && *line != '\0')
		{
			fill_row(row, line, fdf);
			free(line);
			add_row(first_row, row);
		}
		y++;
	}
	if (ret != -1)
		return (first_row);
	else
		return (NULL);
}

int				main(int argc, char **argv)
{
	t_fdf		*fdf;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Warning: Not a valid file\n", 26);
		return (0);
	}
	fdf = (t_fdf *)malloc(sizeof(t_fdf) + 1);
	preferences(fdf);
	fdf->list = read_map(fd, fdf);
	fdf->list = fill_down(fdf->list);
	if (!fdf->list->next)
	{
		write(1, "Empty map\n", 10);
		return (0);
	}
	create(fdf);
	if (argc != 2)
		return (0);
	return (0);
}
