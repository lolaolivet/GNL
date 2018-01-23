/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:21:03 by lolivet           #+#    #+#             */
/*   Updated: 2018/01/23 19:04:06 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

/*
 ** read, malloc and free are autorized
 ** return value must be 1, 0 or -1
 ** the function must return a line read from the file descriptor
 */

int		get_next_line(const int fd, char **line)
{
	int				ret;
	int				i;
	char			buf[BUFF_SIZE + 1];
	static t_gnl	*lst;

	i = 0;
	if (!(lst))
	{
		if (!(lst = (t_gnl*)ft_memalloc(sizeof(t_gnl))))
			return (0);
	}	
	ft_putstr("coucou je suis le reste\n");
	ft_putendl(lst->rest);
	//	ft_putendl(((t_gnl *)lst->content)->rest);
	if (lst->rest && ft_strchr(lst->rest, '\n'))
	{
		while(lst->rest[i])
		{
			if (lst->rest[i] == '\n')
			{
				lst->rest[i] = '\0';
				*line = *line ? ft_strjoin(*line, lst->rest) : ft_strdup(lst->rest); 
				break;
			}
			i++;
		}
		lst->rest = ft_strdup(lst->rest + i + 1);
		return (1);	
	}
	else
		*line = *line ? ft_strjoin(*line, lst->rest) : lst->rest ? ft_strdup(lst->rest) : NULL; 
	while ((ret = read(fd, buf, BUFF_SIZE)) )
	{
		//		si \n
		//		join(line, buf jusqu a \n)
		//		break;
		//		tant que pas de \n
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
	lst->rest = ft_strdup(buf + i + 1);
	lst->fd = fd;
//	ft_putstr(lst->rest);
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
	printf("je suis la line #%s#\n", line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	printf("je suis la line #%s#\n", line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	printf("je suis la line #%s#\n", line);
}
