/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:48:42 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/12 21:17:08 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] > 33 && s[i] < 127)
	{
		while (s[i] != '\0')
		{
			i++;
			k++;
		}
		i--;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			i--;
			k--;
		}
	}
	return (k);
}

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	int		k;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_count(s);
	tmp = (char*)malloc(sizeof(char) * k + 1);
	if (!tmp)
		return (NULL);
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	while (i < k)
	{
		tmp[i] = s[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}
