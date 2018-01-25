/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:04:18 by lolivet           #+#    #+#             */
/*   Updated: 2018/01/25 18:55:51 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int				fd;
	char			*line;
	int				fd2;

	fd = 0;
	line = NULL;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("ERROR");
		return (-1);
	}
	int z;
	//while((z = get_next_line(fd, &line)))
	//{
//	printf("je suis la line retour %d #%s#\n",z, line);
//	ft_strdel(&line);
//	}
	printf("%d", get_next_line(fd, &line));
	printf("je suis la line #%s#\n", line);
	ft_strdel(&line);
	printf("%d", get_next_line(fd, &line));
	printf("je suis la line #%s#\n", line);
	ft_strdel(&line);
	printf("%d", get_next_line(fd, &line));
	printf("je suis la line #%s#\n", line);
	ft_strdel(&line);
	printf("%d", get_next_line(fd, &line));
	printf("je suis la line #%s#\n", line);
	ft_strdel(&line);
	printf("%d", get_next_line(fd, &line));
	printf("je suis la line #%s#\n", line);
	ft_strdel(&line);
}
