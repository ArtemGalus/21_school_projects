/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:12:48 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/03 15:56:50 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall(t_gdata *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->x_id, game->wall.path,
			&game->map_width, &game->map_height);
	if (!game->wall.img)
		ft_checker(1);
}

void	load_ground(t_gdata *game)
{
	game->ground.img = mlx_xpm_file_to_image(game->x_id, game->ground.path,
			&game->map_width, &game->map_height);
	if (!game->ground.img)
		ft_checker(1);
}

void	load_exit(t_gdata *game)
{
	game->exit.img = mlx_xpm_file_to_image(game->x_id, game->exit.path,
			&game->map_width, &game->map_height);
	if (!game->exit.img)
		ft_checker(1);
}

void	load_player(t_gdata *game)
{
	game->player.img = mlx_xpm_file_to_image(game->x_id, game->player.path,
			&game->map_width, &game->map_height);
	if (!game->player.img)
		ft_checker(1);
}

void	load_coin(t_gdata *game)
{
	game->coin.img = mlx_xpm_file_to_image(game->x_id, game->coin.path,
			&game->map_width, &game->map_height);
	if (!game->coin.img)
		ft_checker(1);
}
