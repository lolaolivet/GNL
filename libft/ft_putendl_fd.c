/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:47:11 by lolivet           #+#    #+#             */
/*   Updated: 2017/11/23 14:34:34 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	n;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	n = '\n';
	write(fd, &n, 1);
}
