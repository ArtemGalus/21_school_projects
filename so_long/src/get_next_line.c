/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:55:45 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/31 13:57:03 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_rex	*lst;
	t_rex			*buf;
	int				temp;
	int				i;

	buf = ft_contentcmp(lst, fd);
	temp = ft_1(line, &buf, fd, &lst);
	if (temp <= 0)
		return (ft_meteor(buf, &lst) + temp);
	i = buf->point;
	if (ft_in2line(line, buf, &i, &temp))
		return (ft_meteor(buf, &lst) - 1);
	if (i < temp - 1)
	{
		buf->point = i + 1;
		buf->size = temp;
	}
	if (temp == 0)
		return (ft_meteor(buf, &lst));
	if (i == temp && temp < BUFFER_SIZE)
		return (ft_meteor(buf, &lst));
	if (i == temp - 1)
		buf->point = 0;
	return (1);
}

int	ft_mem(t_rex *buf, int j, int temp, char **line)
{
	int		i;
	char	*bag;

	i = buf->point;
	while (i < temp && (buf->s)[i] != '\n')
		i++;
	bag = malloc(j + i - buf->point + 1);
	if (!bag)
		return (1);
	i = 0;
	while (i++ < j)
		bag[i - 1] = (*line)[i - 1];
	if (j)
		free (*line);
	*line = bag;
	return (0);
}

int	ft_meteor(t_rex *buf, t_rex **lst)
{
	t_rex	*temp;

	if (!*lst || !buf)
		return (0);
	if (buf == *lst)
	{
		*lst = (*lst)->next;
		free(buf);
		buf = 0;
		return (0);
	}
	temp = *lst;
	while (temp->next)
	{
		if (buf == temp->next)
			break ;
		temp = temp->next;
	}
	if ((temp->next)->next)
		temp->next = (temp->next)->next;
	else
		temp->next = 0;
	free(buf);
	buf = 0;
	return (0);
}
