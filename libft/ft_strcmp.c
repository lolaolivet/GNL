/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:52:52 by lolivet           #+#    #+#             */
/*   Updated: 2017/11/21 18:16:10 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	u;
	unsigned char	v;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (s2[i] == '\0')
			return (s1[i]);
		i++;
	}
	u = (unsigned char)s1[i];
	v = (unsigned char)s2[i];
	return (u - v);
}
