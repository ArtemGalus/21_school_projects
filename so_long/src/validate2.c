/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:25:38 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/03 18:26:11 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_cpymap(char ***map, int fd, int count)
{
	int	temp;
	int	i;

	i = 0;
	*map = malloc(sizeof(char *) * (count + 1));
	if (!*map)
		return (1);
	while (i < count)
	{
		temp = get_next_line(fd, &(*map)[i]);
		if (temp < 0)
		{
			ft_free(*map, i);
			return (1);
		}
		i++;
	}
	(*map)[i] = 0;
	return (0);
}

void	ft_free(char **bag, int i)
{
	while (i-- >= 0)
		free(bag[i]);
	free(bag);
}

int	ft_check_extension(char *str)
{
	int		i;
	int		temp;
	char	*s;
	int		y;

	s = "reb.";
	i = 0;
	y = 0;
	temp = -1;
	while (str[i])
	{
		if (str[i] == '/')
			temp = i;
		i++;
	}
	if (ft_strlen(&(str[temp + 1])) < 5)
		return (1);
	while (y < 4)
		if (str[--i] != s[y++])
			return (1);
	return (0);
}
