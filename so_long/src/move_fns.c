/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:37:23 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/03 18:11:59 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_gdata *g_data)
{
	int		x;
	int		y;

	x = g_data->pos_x;
	y = g_data->pos_y;
	if ((*(g_data->map))[y][x] == '1')
		return ;
	else if ((*(g_data->map))[y - 1][x] == '0'
	|| (*(g_data->map))[y - 1][x] == 'C')
	{
		if ((*(g_data->map))[y - 1][x] == 'C')
			g_data->coins -= 1;
		g_data->pos_y -= 1;
		(*(g_data->map))[y][x] = '0';
		(*(g_data->map))[y - 1][x] = 'P';
		g_data->move_count += 1;
		ft_putnbr_fd(g_data->move_count, 1);
		write(1, "\n", 1);
		create_bg(g_data);
		return ;
	}
	else if ((*(g_data->map))[y - 1][x] == 'E')
		if (!g_data->coins)
			ft_checker(0);
}

void	move_down(t_gdata *g_data)
{
	int		x;
	int		y;

	x = g_data->pos_x;
	y = g_data->pos_y;
	if ((*(g_data->map))[y][x] == '1')
		return ;
	else if ((*(g_data->map))[y + 1][x] == '0'
	|| (*(g_data->map))[y + 1][x] == 'C')
	{
		if ((*(g_data->map))[y + 1][x] == 'C')
			g_data->coins -= 1;
		g_data->pos_y += 1;
		(*(g_data->map))[y][x] = '0';
		(*(g_data->map))[y + 1][x] = 'P';
		g_data->move_count += 1;
		ft_putnbr_fd(g_data->move_count, 1);
		write(1, "\n", 1);
		create_bg(g_data);
		return ;
	}
	else if ((*(g_data->map))[y + 1][x] == 'E')
		if (!g_data->coins)
			ft_checker(0);
}

void	move_right(t_gdata *g_data)
{
	int		x;
	int		y;

	x = g_data->pos_x;
	y = g_data->pos_y;
	if ((*(g_data->map))[y][x] == '1')
		return ;
	else if ((*(g_data->map))[y][x + 1] == '0'
	|| (*(g_data->map))[y][x + 1] == 'C')
	{
		if ((*(g_data->map))[y][x + 1] == 'C')
			g_data->coins -= 1;
		g_data->pos_x += 1;
		(*(g_data->map))[y][x] = '0';
		(*(g_data->map))[y][x + 1] = 'P';
		g_data->move_count += 1;
		ft_putnbr_fd(g_data->move_count, 1);
		write(1, "\n", 1);
		create_bg(g_data);
		return ;
	}
	else if ((*(g_data->map))[y][x + 1] == 'E')
		if (!g_data->coins)
			ft_checker(0);
}

void	move_left(t_gdata *g_data)
{
	int		x;
	int		y;

	x = g_data->pos_x;
	y = g_data->pos_y;
	if ((*(g_data->map))[y][x] == '1')
		return ;
	else if ((*(g_data->map))[y][x - 1] == '0'
	|| (*(g_data->map))[y][x - 1] == 'C')
	{
		if ((*(g_data->map))[y][x - 1] == 'C')
			g_data->coins -= 1;
		g_data->pos_x -= 1;
		(*(g_data->map))[y][x] = '0';
		(*(g_data->map))[y][x - 1] = 'P';
		g_data->move_count += 1;
		ft_putnbr_fd(g_data->move_count, 1);
		write(1, "\n", 1);
		create_bg(g_data);
		return ;
	}
	else if ((*(g_data->map))[y][x - 1] == 'E')
		if (!g_data->coins)
			ft_checker(0);
}
