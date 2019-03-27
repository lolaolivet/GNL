/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:08:16 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/12 21:15:23 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putmin(void)
{
	ft_putchar('-');
	ft_putchar('2');
}

void			ft_putnbr(int n)
{
	int		res;
	int		modulo;

	if (n == -2147483648)
	{
		n = 147483648;
		ft_putmin();
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	modulo = (n % 10);
	res = (n / 10);
	if (res != 0)
	{
		ft_putnbr(res);
	}
	ft_putchar(modulo + '0');
}
