/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:49:14 by lolivet           #+#    #+#             */
/*   Updated: 2018/01/29 20:43:45 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

void	fill_rest(t_list *lst, char **ln, int i)
{
	if (ft_strchr(REST, '\n'))
	{
		while (((t_gnl*)(lst->content))->rest[i])
		{
			if (((t_gnl*)(lst->content))->rest[i] == '\n')
			{
				((t_gnl*)(lst->content))->rest[i] = '\0';
				*ln = *ln ? ft_strjoin(*ln, REST) : ft_strdup(REST);
				break ;
			}
			i++;
		}
		REST = ft_strdup(((t_gnl*)(lst->content))->rest + i + 1);
	}
	else
	{
		*ln = ft_strdup(REST);
		ft_strdel(&REST);
		ft_memdel((void**)&lst);
	}
}

int		check_rest(t_list *lst, char **line)
{
	if (!(lst))
		return (0);
	else if (((t_gnl*)(lst->content)) && REST && ft_strchr(REST, '\n'))
	{
		fill_rest(lst, line, 0);
		return (2);
	}
	else
	{
		if (REST)
		{
			*line = ft_strdup(REST);
			return (1);
		}
		else
			return (0);
	}
}

int		read_file(t_list *new, char **line, int fd, int i, int *retour)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		*retour = 1;	
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
	if (ret > 0)
	{
		((t_gnl*)(new->content))->rest = ft_strdup(buf + i);
		((t_gnl*)(new->content))->fd = fd;
		return (1);
	}
	else
			return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*new;
	int				return_check;
	int retour = 0;

	new = NULL;
	if ((return_check = check_rest(lst, line)) == 2)
		return (1);
	if (return_check == -1
			|| !(new = ft_lstnew(ft_memalloc(sizeof(t_gnl)), sizeof(t_gnl*))))
		return (-1);
	if ((return_check = read_file(new, line, fd, 0, &retour)))
	{
		ft_lstadd(&lst, new);
		return (1);
	}
//	printf("je suis le retour du retour %d\n", return_check);
	if (return_check == 0)
	{
		ft_strdel(line);
		return (0);
	}
	//if (*line && printf("je sors d ici\n"))
	//	return (1);
	//else if (*line == NULL)
	//	return (0);
	//else
	//	return (-1);
	return (0);
}
