/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:06:56 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/12 21:15:58 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_nbr(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

static void		ft_fill_nbr(int n, char *tmp, int i)
{
	int		modulo;
	int		res;

	modulo = (n % 10);
	res = (n / 10);
	if (res != 0)
		ft_fill_nbr(res, tmp, i - 1);
	tmp[i] = modulo + '0';
}

char			*ft_itoa(int n)
{
	char	*tmp;
	int		neg;

	neg = 0;
	if (n == -2147483648)
	{
		n = 147483648;
		neg = 2;
	}
	if (n < 0 && (neg = 1))
		n = -n;
	tmp = (char*)malloc(sizeof(char) * ft_count_nbr(n) + 1 + neg);
	if (!tmp)
		return (NULL);
	tmp[ft_count_nbr(n) + neg] = '\0';
	if (neg > 0)
		tmp[0] = '-';
	if (neg == 2)
		tmp[1] = '2';
	ft_fill_nbr(n, tmp, ft_count_nbr(n) + neg - 1);
	return (tmp);
}
