/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:39:47 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/12 21:17:17 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	tmp = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!tmp)
		return (NULL);
	while (s1[j])
	{
		tmp[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		tmp[j + i] = s2[i];
		i++;
	}
	tmp[j + i] = '\0';
	return (tmp);
}
