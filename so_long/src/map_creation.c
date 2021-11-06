/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:37:32 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/03 18:11:30 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_bg(t_gdata *g_data)
{
	int	i;
	int	j;

	i = 0;
	while ((*(g_data->map))[i])
	{
		j = 0;
		while ((*(g_data->map))[i][j])
		{
			if ((*(g_data->map))[i][j] == '1')
				draw_wall(i, j, g_data);
			else
				draw_ground(i, j, g_data);
			j++;
		}
		i++;
	}
	draw_other(g_data);
}

void	draw_other(t_gdata *g_data)
{
	int	i;
	int	j;

	i = 0;
	while ((*(g_data->map))[i])
	{
		j = 0;
		while ((*(g_data->map))[i][j])
		{
			if ((*(g_data->map))[i][j] == 'C')
				draw_coin(i, j, g_data);
			if ((*(g_data->map))[i][j] == 'E')
				draw_exit(i, j, g_data);
			if ((*(g_data->map))[i][j] == 'P')
				draw_player(i, j, g_data);
			j++;
		}
		i++;
	}
}

void	load_textures(t_gdata *game)
{
	game->wall.path = ft_strdup("textures/wall.xpm");
	game->ground.path = ft_strdup("textures/ground.xpm");
	game->exit.path = ft_strdup("textures/exit.xpm");
	game->coin.path = ft_strdup("textures/coin.xpm");
	game->player.path = ft_strdup("textures/player.xpm");
	if (!game->wall.path || !game->ground.path || !game->player.path
		|| !game->exit.path || !game->coin.path)
		ft_checker(1);
	load_wall(game);
	load_ground(game);
	load_exit(game);
	load_player(game);
	load_coin(game);
}
