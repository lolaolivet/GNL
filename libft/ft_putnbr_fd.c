/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:50:11 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/01 11:27:18 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		res;
	int		modulo;
	char	a;

	if (n == -2147483648)
	{
		n = 147483648;
		a = '-';
		write(fd, &a, 1);
		a = '2';
		write(fd, &a, 1);
	}
	if (n < 0)
	{
		n = -n;
		a = '-';
		write(fd, &a, 1);
	}
	modulo = (n % 10);
	res = (n / 10);
	if (res != 0)
		ft_putnbr_fd(res, fd);
	a = modulo + '0';
	write(fd, &a, 1);
}
