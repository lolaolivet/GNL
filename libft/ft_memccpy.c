/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:07:43 by lolivet           #+#    #+#             */
/*   Updated: 2017/11/22 08:31:57 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	i;
	unsigned char	a;
	unsigned char	y;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		y = (unsigned char)s[i];
		d[i] = y;
		i++;
		if (y == a)
		{
			return (&dst[i]);
		}
	}
	return (NULL);
}
