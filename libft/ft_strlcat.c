/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:09:02 by lolivet           #+#    #+#             */
/*   Updated: 2017/11/22 08:34:55 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		k;
	size_t		l;

	i = 0;
	l = 0;
	k = ft_strlen(src);
	while (dst[i] != '\0' && i < size)
		i++;
	if (size)
	{
		while (src[l] && i < (size - 1))
		{
			dst[i] = src[l];
			i++;
			l++;
		}
		if (l)
			dst[i] = '\0';
	}
	return (k + i - l);
}
