/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:34:43 by lolivet           #+#    #+#             */
/*   Updated: 2018/01/15 18:08:53 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	int				ret;
	int				i;
	char			buf[BUFF_SIZE];
	static t_list	*lst;
	t_gnl			*new;
	char			*rest;

	i = 0;
	if (!(lst = (t_list *)malloc(sizeof(t_list))) &&
		/*	!(lst->content = (t_gnl *)malloc(sizeof(t_gnl))) && */
			!(new = (t_gnl *)malloc(sizeof(t_gnl))) &&
			!(new->rest = (char *)malloc(sizeof(char) * (10 + 1))))

		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			while (buf[i])
			{
				if (buf[i] == '\n')
				{
					buf[i] = '\0';
					*line = *line ? ft_strjoin(*line, buf) : ft_strdup(buf);
					break;
				}
				i++;
			}
			break;
		}
		*line = *line ? ft_strjoin(*line, buf) : ft_strdup(buf);
	}
	ft_putstr(*line);
// Mettre dans les bons maillons dans le list -----------
//	((t_gnl *)lst->content)->rest = buf + i + 1;
	new->rest = buf + i + 1;
	lst->content = buf + i + 1;
	ft_putchar('\n');
	ft_putstr(new->rest);
//	ft_putstr(((t_gnl *)lst->content)->rest);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*line = NULL;
	int 		fd2;

	fd = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("ERROR");
		return (-1);
	}
	get_next_line(fd, &line);
//	printf("je suis la line #%s#\n", line);
	ft_strdel(&line);
}
