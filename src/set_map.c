/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:06:50 by rpehkone          #+#    #+#             */
/*   Updated: 2020/03/07 19:45:07 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_rest(int *x, int y, int width, t_xyz *map)
{
	int		height;

	height = get_map_len(0) / width / 2;
	while ((*x) - y * width < width)
	{
		map[(*x)].x = 50 * (((*x) - (y * width)) - width / 2);
		map[(*x)].y = 50 * (y - height);
		map[(*x)].z = 0;
		(*x)++;
	}
}

void	set_map(t_xyz *map, int fd, int width)
{
	int		x;
	int		y;
	int		i;
	char	*line;
	int		height;

	x = 0;
	y = 0;
	height = get_map_len(0) / width / 2;
	while (!(i = 0) && get_next_line(fd, &line))
	{
		while (line[i])
		{
			map[x].x = 50 * ((x - (y * width)) - width / 2);
			map[x].y = 50 * (y - height);
			map[x].z = -10 * ft_atoi(&line[i]);
			while (line[i] && line[i] == ' ')
				i++;
			while (line[i] && line[i] != ' ')
				i++;
			x++;
		}
		set_rest(&x, y, width, map);
		y++;
		free(line);
	}
}
