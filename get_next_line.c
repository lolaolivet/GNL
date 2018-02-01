/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:49:14 by lolivet           #+#    #+#             */
/*   Updated: 2018/02/01 16:46:27 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

void	fill_rest(t_list **lst, char **ln, int i)
{
	t_list	*tmp;

	tmp = *lst;
	while (((t_gnl*)(tmp->content))->rest[i])
	{
		if (((t_gnl*)(tmp->content))->rest[i] == '\n')
		{
			((t_gnl*)(tmp->content))->rest[i] = '\0';
			*ln = *ln ? ft_strjoin(*ln, REST) : ft_strdup(REST);
			break ;
		}
		i++;
	}
	REST = ft_strdup(((t_gnl*)(tmp->content))->rest + i + 1);
}

int		check_rest(t_list **lst, char **line)
{
	t_list		*tmp;

	tmp = *lst;
	if (!(*lst))
		return (0);
	else if (((t_gnl*)(tmp->content)) && REST && ft_strchr(REST, '\n'))
	{
		fill_rest(lst, line, 0);
		return (2);
	}
	else
	{
		if (REST)
		{
			*line = ft_strdup(REST);
			ft_strdel(&REST);
			return (1);
		}
		else
		{
			ft_strdel(line);
			return (0);
		}
	}
}

int		check_read(t_list **new, int ret, char *buf, int j)
{
	t_list			*tmp;

	tmp = *new;
	if (ret < 0)
		return (-1);
	else if (ret > 0)
	{
		REST = ft_strdup(buf);
		return (1);
	}
	else if (j)
	{
		REST = NULL;
		return (1);
	}
	else
		return (0);
}

int		read_file(t_list *new, char **line, int fd, int i)
{
	int				ret;
	int				j;
	char			buf[BUFF_SIZE + 1];
	int				return_read;

	j = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		j = 1;
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			while (buf[i])
				if (buf[i++] == '\n' && ((buf[i - 1] = '\0') + 1))
				{
					*line = *line ? ft_strjoin(*line, buf) : ft_strdup(buf);
					break ;
				}
			break ;
		}
		*line = *line ? ft_strjoin(*line, buf) : ft_strdup(buf);
	}
	((t_gnl*)(new->content))->fd = fd;
	return_read = check_read(&new, ret, buf + i, j);
	return (return_read);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*new;
	int				return_check;
	int				return_read;

	new = NULL;
	if (line)
		*line = NULL;
	if ((return_check = check_rest(&lst, line)) == 2)
		return (1);
	if (return_check == -1 || fd < 0
			|| !(new = ft_lstnew(ft_memalloc(sizeof(t_gnl)), sizeof(t_gnl*)))
			|| (return_read = read_file(new, line, fd, 0)) == -1)
		return (-1);
	if (return_read == 1 || ((return_read == 0 && return_check == 1) &&
				ft_strlen(*line)))
	{
		ft_lstadd(&lst, new);
		return (1);
	}
	else
	{
		ft_strdel(line);
		return (0);
	}
}
