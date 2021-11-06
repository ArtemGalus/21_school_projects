/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:13:37 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/05 17:56:20 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate(char **argv, char ***map)
{
	int	fd;
	int	count;
	int	*ar;

	ar = malloc(sizeof(int) * 5);
	if (!ar)
		ft_checker(1);
	ft_bzero(ar, sizeof(int) * 6);
	if (ft_check_extension(argv[1]))
		ft_checker(1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_checker(1);
	count = ft_columns_count(fd, &ar);
	close(fd);
	if (ft_check_map(ar) || count < 0)
		ft_checker(1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_checker(1);
	if (ft_cpymap(map, fd, count))
		ft_checker(1);
	close (fd);
	return (count);
}

int	ft_check_map(int *ar)
{	
	if (!ar[1] || ar[2] < 0 || ar[3] < 1 || ar[4] != 1 || ar[5] != 1)
		return (1);
	return (0);
}

int	ft_columns_count(int fd, int **ar)
{
	int		count;
	int		temp;
	char	*str;

	count = 0;
	temp = get_next_line(fd, &str);
	if (temp < 0)
		ft_checker(1);
	(*ar)[0] = ft_strlen(str);
	while (1)
	{
		if (temp < 0 || (int)ft_strlen(str) != *ar[0])
			ft_checker(1);
		if ((!count || !temp) && ft_checkLine(ar, str, 1))
			break ;
		if (count && temp && ft_checkLine(ar, str, 0))
			break ;
		free(str);
		if (!temp)
			return (count + 1);
		temp = get_next_line(fd, &str);
		count ++;
	}
	return (count);
}

int	ft_checkLine(int **ar, char *str, int flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (flag == 1)
			if (str[i] != '1')
				(*ar)[2] = -1;
		if (flag != 1)
		{
			if (!ft_strcmp2(ar, str[i]))
				(*ar)[2] = -1;
		}
		i++;
	}
	if (str[0] != '1' || str[i - 1] != '1')
		(*ar)[2] = -1;
	if ((*ar)[2] < 0)
		return (1);
	return (0);
}

int	ft_strcmp2(int **ar, char c)
{
	char	*s;
	int		i;

	s = "01CEP";
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			(*ar)[i + 1] += 1;
			return (1);
		}
		i++;
	}
	return (0);
}
