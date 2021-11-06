/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:31:59 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/03 18:09:51 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(int i, int j, t_gdata *game)
{
	mlx_put_image_to_window(game->x_id, game->win,
		game->wall.img, j * 64, i * 64);
}

void	draw_ground(int i, int j, t_gdata *game)
{
	mlx_put_image_to_window(game->x_id, game->win,
		game->ground.img, j * 64, i * 64);
}

void	draw_exit(int i, int j, t_gdata *game)
{
	mlx_put_image_to_window(game->x_id, game->win,
		game->exit.img, j * 64, i * 64);
}

void	draw_player(int i, int j, t_gdata *game)
{
	mlx_put_image_to_window(game->x_id, game->win,
		game->player.img, j * 64, i * 64);
}

void	draw_coin(int i, int j, t_gdata *game)
{
	mlx_put_image_to_window(game->x_id, game->win,
		game->coin.img, j * 64, i * 64);
}
