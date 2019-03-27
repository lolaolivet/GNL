/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:10:27 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/01 08:07:25 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	j = len;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (len == 0)
		return (d);
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		ft_memcpy(d, s, len);
	}
	return (d);
}
