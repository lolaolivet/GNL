/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:48:13 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/02 12:18:55 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int		i;
	char				*str;

	str = (char*)s;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	if (i == 0 && str[i] == c)
		return (&str[i]);
	return (NULL);
}
