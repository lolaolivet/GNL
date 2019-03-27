/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:28:54 by lolivet           #+#    #+#             */
/*   Updated: 2018/02/08 18:30:39 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

void	fill_rest(char **rest, char **ln, int i)
{
	char		*tmp;

	tmp = *rest;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			tmp[i] = '\0';
			*ln = *ln ? ft_strjoin(*ln, tmp) : ft_strdup(tmp);
			break ;
		}
		i++;
	}
	*rest = ft_strdup(tmp + i + 1);
}

int		check_rest(char **rest, char **line)
{
	if (!(*rest))
		return (0);
	else if (*rest && ft_strchr(*rest, '\n'))
	{
		fill_rest(rest, line, 0);
		return (2);
	}
	else
	{
		if (*rest)
		{
			*line = ft_strdup(*rest);
			free(*rest);
			*rest = NULL;
			return (1);
		}
		else
		{
			ft_strdel(line);
			free(*rest);
			*rest = NULL;
			return (0);
		}
	}
}

int		check_read(char **rest, int ret, char *buf, int j)
{
	if (ret < 0)
	{
		free(*rest);
		return (-1);
	}
	else if (ret > 0)
	{
		*rest = ft_strdup(buf);
		return (1);
	}
	else if (j)
		return (1);
	else
	{
		free(*rest);
		*rest = NULL;
		return (0);
	}
}

int		read_file(char **rest, char **ln, int fd, int i)
{
	int			return_read;
	t_gnl		t;

	t.j = 0;
	while ((t.ret = read(fd, t.buf, BUFF_SIZE)) > 0)
	{
		t.j = 1;
		t.buf[t.ret] = '\0';
		if (ft_strchr(t.buf, '\n'))
		{
			while (t.buf[i])
				if (t.buf[i++] == '\n' && ((t.buf[i - 1] = '\0') + 1))
				{
					t.tmp = *ln;
					*ln = *ln ? ft_strjoin(*ln, t.buf) : ft_strdup(t.buf);
					free(t.tmp);
					break ;
				}
			break ;
		}
		t.tmp = *ln;
		*ln = *ln ? ft_strjoin(*ln, t.buf) : ft_strdup(t.buf);
		free(t.tmp);
	}
	return ((return_read = check_read(rest, t.ret, t.buf + i, t.j)));
}

int		get_next_line(const int fd, char **line)
{
	static char	*rest = NULL;
	int			check;
	int			read;

	if (line)
		*line = NULL;
	if ((check = check_rest(&rest, line)) == 2)
		return (1);
	if (check == -1 || fd < 0 || (read = read_file(&rest, line, fd, 0)) == -1)
	{
		ft_strdel(line);
		ft_strdel(&rest);
		return (-1);
	}
	if (read == 1 || ((read == 0 && check == 1) && ft_strlen(*line)))
		return (1);
	else
	{
		ft_strdel(line);
		ft_strdel(&rest);
		return (0);
	}
}
