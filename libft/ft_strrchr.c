/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:52:42 by rpehkone          #+#    #+#             */
/*   Updated: 2019/10/24 14:20:44 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *p;

	p = NULL;
	while (*s)
	{
		if (*s == c)
			p = (char*)s;
		s++;
	}
	if (!c)
		p = (char*)s;
	return (p);
}
