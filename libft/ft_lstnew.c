/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 08:32:54 by lolivet           #+#    #+#             */
/*   Updated: 2017/12/06 09:31:51 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content = (void*)malloc(sizeof(void) * content_size);
		tmp->content_size = content_size;
		ft_memcpy(tmp->content, content, content_size);
	}
	tmp->next = NULL;
	return (tmp);
}
