/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:55:38 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/31 13:57:04 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_new_elem2back(t_rex **lst, int fd)
{
	t_rex	*new;
	t_rex	*temp;

	new = malloc(sizeof(t_rex));
	if (!new)
		return (0);
	new->fd = fd;
	new->point = 0;
	new->next = 0;
	new->size = 0;
	if (!(*lst))
	{
		*lst = new;
		return (1);
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (1);
}

t_rex	*ft_contentcmp(t_rex *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_1(char **line, t_rex **buf, int fd, t_rex **lst)
{
	int	temp;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	if (!*buf)
	{
		if (!ft_new_elem2back(lst, fd))
			return (-1);
		*buf = ft_contentcmp(*lst, fd);
	}
	if (!(*buf)->point)
	{
		temp = read((*buf)->fd, (*buf)->s, BUFFER_SIZE);
		if (temp == -1)
			return (-1);
		(*buf)->size = temp;
		if (!temp)
		{
			if (ft_mem(*buf, 0, 0, line))
				return (-1);
			**line = 0;
			return (0);
		}
	}
	return ((*buf)->size);
}

int	ft_in2line(char **line, t_rex *buf, int *i, int *temp)
{
	int	j;

	j = 0;
	if (ft_mem(buf, j, *temp, line))
		return (1);
	while (*i < *temp && (buf->s)[*i] != '\n')
	{
		(*line)[j++] = (buf->s)[(*i)++];
		if (*i == *temp && *temp == BUFFER_SIZE)
		{
			*i = 0;
			buf->point = 0;
			*temp = read(buf->fd, buf->s, BUFFER_SIZE);
			if (*temp == -1 || ft_mem(buf, j, *temp, line))
				return (1);
		}
	}
	(*line)[j] = 0;
	return (0);
}
