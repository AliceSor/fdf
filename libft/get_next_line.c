/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:29:24 by asoroka           #+#    #+#             */
/*   Updated: 2017/02/25 17:42:27 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_n(char **line, char **temp)
{
	char		*pos_n;

	pos_n = ft_strchr(*line, '\n');
	if (pos_n)
	{
		*pos_n = '\0';
		*temp = ft_strdup(pos_n + 1);
		return (1);
	}
	return (0);
}

static int		read_fd(int fd, char **line, char **temp)
{
	char		buff[BUFF_SIZE + 1];
	int			res;

	ft_bzero(buff, BUFF_SIZE + 1);
	if (find_n(line, temp))
		return (1);
	while ((res = read(fd, buff, BUFF_SIZE) > 0))
	{
		*temp = *line;
		*line = ft_strjoin(*line, buff);
		free(*temp);
		if (find_n(line, temp))
			return (1);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	*temp = ft_strdup("\0");
	if ((*line) && (*line)[0])
		return (1);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static char	*temp;
	int			result;

	if (fd < 0 || !line || (result = read(fd, NULL, 0) < 0))
		return (-1);
	*line = ft_strdup(temp == 0 ? "\0" : temp);
	return (read_fd(fd, line, &temp));
}
