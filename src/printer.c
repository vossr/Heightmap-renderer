/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:44:10 by rpehkone          #+#    #+#             */
/*   Updated: 2020/03/07 21:39:06 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xyz	get_color(int set)
{
	static t_xyz	color = {.x = -1};

	if (color.x == -1)
	{
		color.x = 0xFFFFFF;
		color.y = 0xFFFFFF;
		color.z = 0;
	}
	if (set == -2)
		cycle_colors(&color);
	else if (set)
	{
		color.x = set;
		color.y = set;
	}
	if (get_settings(7, NULL))
		return (add_color_height(color));
	return (color);
}

void	move_center(t_xyz *start, t_xyz *stop, int reset)
{
	static double	zoom = -600;
	static int		w_move = 0;
	static int		h_move = 0;

	if (reset)
		zoom = -1 * get_map_len(0) / 2;
	if (reset)
		return ;
	if (get_settings(0, NULL) && is_mouse_down(4))
		zoom += 0.07;
	if (get_settings(0, NULL) && is_mouse_down(5))
		zoom -= 0.07;
	zoom = zoom > 600 ? 600 : zoom;
	zoom = zoom < -4000 ? -4000 : zoom;
	start->z -= zoom;
	stop->z -= zoom;
	if (!get_settings(1, NULL))
		add_perspective(start, stop, 0);
	w_move = w_move ? w_move : get_width(NULL) / 2;
	h_move = h_move ? h_move : get_height(NULL) / 2 + 30;
	start->x += w_move;
	start->y += h_move;
	stop->x += w_move;
	stop->y += h_move;
	print_line(*start, *stop, get_color(0));
}

void	center_image(t_xyz *start, t_xyz *stop, int reset)
{
	static int	x = 0;
	static int	y = 0;
	static int	coordx = 0;
	static int	coordy = 0;
	t_int_xy	cursor;

	if (reset)
	{
		x = 0;
		y = 0;
		return ;
	}
	cursor = get_cursor();
	if (get_settings(0, NULL) && is_mouse_down(3))
		x -= coordx - cursor.x;
	if (get_settings(0, NULL) && is_mouse_down(3))
		y -= coordy - cursor.y;
	coordx = cursor.x;
	coordy = cursor.y;
	start->x += x;
	start->y += y;
	stop->x += x;
	stop->y += y;
	move_center(start, stop, 0);
}

void	draw2(t_xyz *nodes, int map_len)
{
	t_xyz			start;
	t_xyz			stop;
	static int		width = 0;
	int				i;

	if (!width)
		width = get_map_width(0);
	i = -1;
	while (++i < map_len)
	{
		save_coord(i, i + 1, 0);
		if ((i + 1) % width)
		{
			start = nodes[i];
			stop = nodes[i + 1];
			center_image(&start, &stop, 0);
		}
		save_coord(i, i + width, 0);
		if (i + width < map_len)
		{
			start = nodes[i];
			stop = nodes[i + width];
			center_image(&start, &stop, 0);
		}
	}
}

void	draw(t_xyz *nodes, int map_len, int reset)
{
	static float	origo_len = 1;
	//static int	origo_len = 1025;
	int		i;
if (reset)
	{
		//origo_len = 1025;
		return ;
	}
	if (get_settings(2, NULL))
		slider(&origo_len);
	else if (get_settings(4, NULL))
		gradient();
	i = -1;
	while (++i < map_len)
		nodes[i].z += ((origo_len + 2) * 500);
	draw2(nodes, map_len);
	//i = -1;
	//while (++i < map_len)
		//nodes[i].z -= origo_len;
	if (get_settings(5, NULL))
		get_color(-2);
}
