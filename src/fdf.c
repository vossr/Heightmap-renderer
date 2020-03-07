/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:49:05 by rpehkone          #+#    #+#             */
/*   Updated: 2020/03/07 12:50:17 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix_transform(t_xyz *nodes, int amount)
{
	static int	x = 0;
	static int	y = 0;
	t_xyz		cursor;

	cursor = get_cursor(0, 0, NULL);
	if (get_settings(3, NULL))
		rotate_y((float)0.01, nodes, amount);
	if (get_settings(0, NULL) && is_mouse_down(0, 1))
		rotate_y((float)0.01 * (x - cursor.x), nodes, amount);
	if (get_settings(0, NULL) && is_mouse_down(0, 1))
		rotate_x(-1 * (float)0.01 * (y - cursor.y), nodes, amount);
	x = cursor.x;
	y = cursor.y;
}

void	reset(void)
{
	int i;

	i = 1;
	while (i <= 9)
	{
		get_settings(-1 * i, NULL);
		i++;
	}
	get_color(0xFFFFFF);
}

int		matrix(void **mlx)
{
	static t_xyz	*nodes = NULL;
	static int		amount = 0;

	if (!nodes || get_settings(9, NULL))
	{
		nodes = make_map(NULL, 0);
		rotate_x(-1, nodes, get_map_len(0));
		rotate_y(1, nodes, get_map_len(0));
		reset();
	}
	if (!amount)
		amount = get_map_len(0);
	mlx_clear_window(mlx[0], mlx[1]);
	mlx_put_image_to_window(mlx[0], mlx[1], mlx[2], 0, 0);
	mlx_clear_image(mlx);
	matrix_transform(nodes, amount);
	draw(nodes, amount, mlx);
	return (0);
}

int		fdf(void **mlx)
{
	matrix(mlx);
	buttons_loop(mlx);
	help_text(mlx);
	return (0);
}
