/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:26:00 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/12 20:57:33 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
