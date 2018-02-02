/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:28:54 by lolivet           #+#    #+#             */
/*   Updated: 2018/02/02 20:04:39 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

void	fill_rest(char **rest, char **ln, int i)
{
	char		*tmp;
	char		*tnt;

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
	tnt = *rest;
	*rest = ft_strdup(tmp + i + 1);
	free(tmp);
	free(tnt);
}

int		check_rest(char **rest, char **line)
{
	//char	*tmp;

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
			// Ici 
		//	free(*rest);
		//	*rest = ft_strnew(0);
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
		*rest = NULL;
		return (0);
	}
}

int		read_file(char **rest, char **line, int fd, int i)
{
	int			ret;
	int			j;
	char		buf[BUFF_SIZE + 1];
	int			return_read;
	char		*tmp;

	j = 0;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		j = 1;
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			while (buf[i])
				if (buf[i++] == '\n' && ((buf[i - 1] = '\0') + 1))
				{
					/*
					if (*line)
						tmp = ft_strjoin(*line, buf);
					else
						*line = ft_strdup(buf);
						*/
					tmp = *line;
					*line = *line  ? ft_strjoin(*line, buf) : ft_strdup(buf);
//					ft_putendl(*line);
					free(tmp);
					break ;
				}
			break ;
		}
		tmp = *line;
		*line = *line ? ft_strjoin(*line, buf) : ft_strdup(buf);
		free(tmp);
	}
	return_read = check_read(rest, ret, buf + i, j);
	return (return_read);
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
		free(rest);
		return (-1);
	}
	if (read == 1 || ((read == 0 && check == 1) && ft_strlen(*line)))
	{
// Pas de fautes dans FileCheck mais 354 leaks, 1 byte avec valgrind,
//  0 leaks avec while(1)
//		if (read == 0)
//			free(rest);
// 
//		if (read == 0 || check == 0)
//			free(rest);
		return (1);
	}
	else
	{
		ft_strdel(line);
		free(rest);
		return (0);
	}
}
