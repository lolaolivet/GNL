/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:22:33 by lolivet           #+#    #+#             */
/*   Updated: 2017/11/23 16:07:12 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*d;

	i = 0;
	c = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (i < n)
	{
		if (c[i] != d[i])
			return ((int)(c[i] - d[i]));
		i++;
	}
	return (0);
}
