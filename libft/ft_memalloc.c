/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:59:48 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/12 21:14:33 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*tmp;
	size_t	i;

	i = 0;
	if (!size)
		return (NULL);
	tmp = (size_t*)malloc(sizeof(size_t) * size);
	if (!tmp)
		return (NULL);
	while (tmp[i])
	{
		if (i <= size)
		{
			tmp[i] = 0;
			i++;
		}
		else
			return (NULL);
	}
	return (tmp);
}
