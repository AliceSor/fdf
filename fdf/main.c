/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:33:35 by asoroka           #+#    #+#             */
/*   Updated: 2017/03/04 19:23:29 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_row(t_row *row, char *line)
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
		while (l[++x])
		{
			point = new_point(x, row->y);
			if ((n = strchr(l[x], ',')))
			{
				*n = '\0';
			//	point->color = atoh(n + 1);
			}
			else
				point->color = 16777215;
			point->z = ft_atoi(l[x]);
			if (point->z != 0)
				point->color = 0xFFFF;
			add_point(first_point, point);
		}
}

static t_row	*read_map(int fd)
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
		fill_row(row, line);
		add_row(first_row, row);
		y++;
	}
	return (first_row);
}

int				main(int argc, char **argv)
{
	t_fdf		*fdf;

	int			fd;

	fdf = (t_fdf *)malloc(sizeof(t_fdf) + 1);
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	fd = open(argv[1], O_RDONLY);
	fdf->list = read_map(fd);
	fdf->list = fill_down(fdf->list);
    fdf->pos_x = 400;
    fdf->pos_y = 400;
	create(fdf);

	if (argc != 2)
		return (1);
	return (1);
}
