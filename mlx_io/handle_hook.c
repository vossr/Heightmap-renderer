/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:17:33 by rpehkone          #+#    #+#             */
/*   Updated: 2020/03/12 20:09:41 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_io.h"

int		handle_keyboard_down(int key)
{
	set_key(1, key);
	loop_hook();
	return (0);
}

int		handle_keyboard_up(int key)
{
	set_key(2, key);
	loop_hook();
	return (0);
}

int		handle_mouse_down(int button, int x, int y)
{
	set_mouse(1, button);
	set_cursor(1, x, y);
	loop_hook();
	if (button == 4 || button == 5)
		set_mouse(2, button);
	return (0);
}

int		handle_mouse_up(int button, int x, int y)
{
	set_mouse(2, button);
	set_cursor(1, x, y);
	loop_hook();
	return (0);
}

int		handle_cursor(int x, int y)
{
	set_cursor(1, x, y);
	loop_hook();
	return (0);
}
