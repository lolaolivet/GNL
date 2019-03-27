/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:15:42 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/12 21:16:15 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c, int i, int w)
{
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			w++;
		}
		else
			i++;
	}
	return (w);
}

static void		ft_count_char(char **tmp, char const *s, char c, int i)
{
	int		l;
	int		j;

	l = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				l++;
				i++;
			}
			tmp[j] = (char*)malloc(sizeof(char) * l + 1);
			j++;
			l = 0;
		}
		else
			i++;
	}
}

static char		*ft_fill_tmp(char **tmp, char const *s, char c, int i)
{
	int		k;
	int		j;

	k = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				tmp[j][k] = s[i];
				k++;
				i++;
			}
			tmp[j][k] = '\0';
			k = 0;
			j++;
		}
		else
			i++;
	}
	tmp[j] = NULL;
	return (*tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int		k;

	if (!s)
		return (NULL);
	k = ft_count_word(s, c, 0, 0);
	tmp = (char**)malloc(sizeof(char*) * k + 1);
	if (!tmp)
		return (NULL);
	ft_count_char(tmp, s, c, 0);
	ft_fill_tmp(tmp, s, c, 0);
	return (tmp);
}
