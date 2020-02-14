/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:12:01 by rpehkone          #+#    #+#             */
/*   Updated: 2019/10/31 10:40:04 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	str--;
	while (len--)
		if (*++str == (unsigned char)c)
			return (str);
	return (NULL);
}
