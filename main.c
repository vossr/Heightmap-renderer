/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:49:05 by rpehkone          #+#    #+#             */
/*   Updated: 2020/01/27 19:20:50 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int call, int x, int y, void **mlx);

int		handle_loop(void **mlx)
{
	static int i = 0;

	i++;
	if (i < 200)
		return (0);
	i = 0;
	deal_key(1, 0, 0, mlx);
	return (0);
}

int		handle_keyboard_down(int key, void **mlx)
{
	printf("kd k = %d\n", key);
	if (key == 53)
		exit(0);
	deal_key(2, key, 0, mlx);
	return (0);
}

int		handle_keyboard_up(int key, void **mlx)
{
	printf("ky k = %d\n", key);
	deal_key(3, key, 0, mlx);
	return (0);
}

int		handle_mouse_down(int button, int x, int y, void **mlx)
{
	printf("m_down b = %d\n", button);
	deal_key(4, button, 0, mlx);
	return (0);
}

int		handle_mouse_up(int button, int x, int y, void **mlx)
{
	printf("m_up b = %d\n", button);
	deal_key(5, button, 0, mlx);
	return (0);
}

int		handle_cursor(int x, int y, void **mlx)
{
	//printf("x = %d, y = %d\n", x, y);
	deal_key(6, x, y, mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	**mlx;

	if (argc != 2)
		exit (0);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdf");
	mlx = (void**)malloc(sizeof(void*) * 3);
	mlx[0] = mlx_ptr;
	mlx[1] = win_ptr;
	mlx[2] = argv[1];
	deal_key(0, 0, 0, mlx);
	mlx_hook(win_ptr, 2, 0, handle_keyboard_down, mlx);
	mlx_hook(win_ptr, 3, 0, handle_keyboard_up, mlx);
	mlx_hook(win_ptr, 4, 0, handle_mouse_down, mlx);
	mlx_hook(win_ptr, 5, 0, handle_mouse_up, mlx);
	mlx_hook(win_ptr, 6, 0, handle_cursor, mlx);
	mlx_loop_hook(mlx_ptr, handle_loop, mlx);
	mlx_loop(mlx_ptr);
	return (1);
}
