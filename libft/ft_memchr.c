/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:55:19 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/01 11:21:09 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	i;
	unsigned char	uc;
	unsigned char	*str;
	unsigned char	ustr;
	void			*uv;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n)
	{
		ustr = (unsigned char)str[i];
		if (ustr == uc)
		{
			uv = (void*)s;
			return (uv + i);
		}
		i++;
	}
	return (NULL);
}
