/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:21:03 by lolivet           #+#    #+#             */
/*   Updated: 2018/01/15 18:08:55 by lolivet          ###   ########.fr       */
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
	static t_list	*lst;
	t_list			*new;
	char			*reste;

	i = 0;
	if (!(lst = (t_list *)malloc(sizeof(t_list))) &&
			!(new = (t_list *)malloc(sizeof(t_list))) &&
			!(new->content = (t_gnl *)malloc(sizeof(t_gnl))) &&
			!(lst->content = (t_gnl *)malloc(sizeof(t_gnl))) &&
			!(((t_gnl *)new->content)->rest = (char *)malloc(sizeof(char))))
		return (0);
	ft_putstr("coucou je suis le reste\n");
	ft_putendl(reste);
//	ft_putendl(((t_gnl *)lst->content)->rest);
	if (reste && ft_strchr(reste, '\n'))
	{
		while(reste[i])
		{
			if (reste[i] == '\n')
			{
				reste[i] = '\0';
				*line = *line ? ft_strjoin(*line, reste) : ft_strdup(reste); 
				break;
			}
			i++;
		}
		reste = ft_strdup(reste + i + 1);
		return (1);	
	}
	else
		*line = *line ? ft_strjoin(*line, reste) : reste ? ft_strdup(reste) : NULL; 


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
		ft_putstr("0");
	}

	//	((t_gnl *)new->content)->rest = ft_strdup(buf + i + 1);
	//	((t_gnl *)new->content)->fd = fd;
	//			ft_lstadd(&lst, new);
	//	ft_putchar('\n');
	//	ft_putchar('\n');
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
	/*
	   get_next_line(fd, &line);
	   printf("je suis la line #%s#\n", line);
	   ft_strdel(&line);
	   get_next_line(fd, &line);
	   printf("je suis la line #%s#\n", line);
	   */
}
