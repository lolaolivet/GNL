/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:34:43 by lolivet           #+#    #+#             */
/*   Updated: 2018/01/25 18:55:48 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>
#define	REST ((t_gnl*)(lst->content))->rest
void	fill_rest(t_list *lst, char **ln, int i)
{
	while (((t_gnl*)(lst->content))->rest[i])
	{
		if (((t_gnl*)(lst->content))->rest[i] == '\n')
		{
			((t_gnl*)(lst->content))->rest[i] = '\0';
			*ln = *ln ?	ft_strjoin(*ln, REST) :	ft_strdup(REST);
			ft_putstr("line: ");
			ft_putstr(*ln);
			ft_putchar('\n');
			break ;
		}
		i++;
	}
	REST = ft_strdup(((t_gnl*)(lst->content))->rest + i + 1);
	ft_putstr("rest: ");
	ft_putstr(REST);
	ft_putstr("\n");
}

int		check_rest(t_list *lst, char **line, int i)
{
	if (!(lst))
	{
		//		if (!(lst = ft_lstnew(ft_memalloc(sizeof(t_gnl)), sizeof(t_gnl*))))
		//		{
		//			ft_putstr("FAIL");
		//			return (-1);
		//		}
		return (0);
	}
	ft_putstr(REST);
	ft_putchar('\n');
	if (((t_gnl*)(lst->content)) && ((t_gnl*)(lst->content))->rest &&
			ft_strchr(REST, '\n'))
	{
		fill_rest(lst, line, 0);
		return (1);
	}
	if (*line)
	{
		ft_putstr("if line");
		*line = ft_strjoin(*line, REST);
		return (1);
	}
	else
	{
		if (REST)
		{
			ft_putstr("if rest");
			*line = ft_strdup(REST);
			ft_putstr(REST);
			return (1);
		}
		else
		{
			return (0);
		}
	}
}

int	read_file(t_list *lst, t_list *new, char **line, int fd)
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
				if (buf[i++] == '\n' && ((buf[i - 1] = '\0') + 1))
				{
					*line = *line ? ft_strjoin(*line, buf) : ft_strdup(buf);
					break ;
				}
			break ;
		}
		*line = *line ? ft_strjoin(*line, buf) : ft_strdup(buf);
	}
	//ft_putstr("rest\n");
	//	ft_putstr(buf + i + 1);
	if (ret > 0)
	{
		((t_gnl*)(new->content))->rest = ft_strdup(buf + i);
		return (1);
	}
	else 
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*new = NULL;

	//	if (lst)
	//	{
	///	ft_putstr("vive la france du general\n");
	//	ft_putstr(REST);
	//	}
	if (check_rest(lst, line, 0) == -1
			|| !(new = ft_lstnew(ft_memalloc(sizeof(t_gnl)), sizeof(t_gnl*))))
		return (-1);

	if (read_file(lst, new, line, fd))
	{
		((t_gnl*)(new->content))->fd = fd;
		ft_lstadd(&lst, new);
	}
	//	if (lst)
	//	{
	//	ft_putstr("rire c est bon pour la sante comme dit le dicton populaiiiiire\n");
	//	ft_putstr(REST);
	//	}
	if (*line)
		return (1);
	else if (*line == NULL)
		return (0);
	else
		return (-1);
	ft_memdel((void *)&new);
}
