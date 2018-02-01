/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:21:14 by lolivet           #+#    #+#             */
/*   Updated: 2018/01/30 11:54:23 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 32
# define REST ((t_gnl*)(tmp->content))->rest

typedef struct	s_gnl
{
	int			fd;
	char		*rest;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
