/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:21:14 by lolivet           #+#    #+#             */
/*   Updated: 2018/02/08 19:01:50 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 32

typedef struct	s_gnl
{
	int			ret;
	int			j;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
