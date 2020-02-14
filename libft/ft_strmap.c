/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:28:58 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/07 16:34:49 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	char	*fresh;

	size = 0;
	if (!s)
		return (0);
	while (s[size])
		size++;
	if (!(fresh = (char*)malloc(sizeof(fresh) * (size + 1))))
		return (NULL);
	fresh[size] = '\0';
	size = 0;
	while (*s)
	{
		fresh[size] = f(*s);
		s++;
		size++;
	}
	return (fresh);
}
