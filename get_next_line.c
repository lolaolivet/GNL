/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:34:43 by lolivet           #+#    #+#             */
/*   Updated: 2018/01/24 19:05:50 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

void	fill_rest(t_list *lst, char **line, int i)
{
	while (((t_gnl*)(lst->content))->rest[i])
	{
		if (((t_gnl*)(lst->content))->rest[i] == '\n')
		{
			((t_gnl*)(lst->content))->rest[i] = '\0';
			*line = *line ?
				ft_strjoin(*line, ((t_gnl*)(lst->content))->rest) :
				ft_strdup(((t_gnl*)(lst->content))->rest);
			break ;
		}
		i++;
	}
	((t_gnl*)(lst->content))->rest =
		ft_strdup(((t_gnl*)(lst->content))->rest + i + 1);
}

int		check_rest(t_list *lst, char **line, int i)
{
	if (!(lst))
	{
		if (!(lst = ft_lstnew(ft_memalloc(sizeof(t_gnl)), sizeof(t_gnl*))))
			return (-1);
	}
	if (((t_gnl*)(lst->content))->rest &&
			ft_strchr(((t_gnl*)(lst->content))->rest, '\n'))
	{
		fill_rest(lst, line, 0);
		return (1);
	}
	else
	{
		if (*line)
		{
			*line = ft_strjoin(*line, ((t_gnl*)(lst->content))->rest);
			return (1);
		}
		else
		{
			if (((t_gnl*)(lst->content))->rest)
			{
				*line = ft_strdup(((t_gnl*)(lst->content))->rest);
				return (1);
			}
			else
				return (0);
		}
	}
}

void	read_file(t_list *lst, t_list *new, char **line, int fd)
{
	int				i;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
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
					break ;
				}
				i++;
			}
			break ;
		}
		*line = *line ? ft_strjoin(*line, buf) : ft_strdup(buf);
	}
	if (ret != 0)
		((t_gnl*)(new->content))->rest = ft_strdup(buf + i + 1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*new;

	check_rest(lst, line, 0);
	new = ft_lstnew(ft_memalloc(sizeof(t_gnl)), sizeof(t_gnl*));
	read_file(lst, new, line, fd);
	((t_gnl*)(new->content))->fd = fd;
	ft_lstadd(&lst, new);
	return (0);
}

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
