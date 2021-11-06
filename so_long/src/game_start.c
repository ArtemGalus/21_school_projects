/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:46:32 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/03 18:10:53 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(char ***map, t_gdata *game)
{
	game->map = map;
	game->x_id = mlx_init();
	game->win = mlx_new_window(game->x_id, game->map_width * 64,
			game->map_height * 64, "so_long");
	get_stat(game);
	load_textures(game);
	create_bg(game);
	ft_putnbr_fd(game->move_count, 1);
	write(1, "\n", 1);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 131072L, close_window, game);
	mlx_loop(game->x_id);
}

int	key_hook(int key, t_gdata *game)
{
	(void)game;
	if (key == 53)
		exit(0);
	else if (key == 0)
		move_left(game);
	else if (key == 1)
		move_down(game);
	else if (key == 2)
		move_right(game);
	else if (key == 13)
		move_up(game);
	return (0);
}

int	close_window(int key, t_gdata **game)
{
	(void) key;
	(void) game;
	exit(0);
}
