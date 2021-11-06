/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:37:43 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/05 18:02:41 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_gdata	*game;

	if (argc != 2)
		ft_checker(1);
	game = malloc(sizeof(t_gdata));
	if (!game)
		ft_checker(1);
	game->map_height = ft_validate(argv, &map);
	game->map_width = ft_strlen(*map);
	start_game(&map, game);
}

void	ft_checker(int i)
{
	if (i)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	if (!i)
	{
		write (1, "You are winner!\n", 16);
		exit (0);
	}
}

void	get_stat(t_gdata *game)
{
	int	i;
	int	j;

	i = 0;
	game->coins = 0;
	game->move_count = 0;
	while ((*(game->map))[i])
	{
		j = 0;
		while ((*(game->map))[i][j])
		{
			if ((*(game->map))[i][j] == 'P')
			{
				game->pos_x = j;
				game->pos_y = i;
			}
			if ((*(game->map))[i][j] == 'C')
				game->coins++;
			j++;
		}
		i++;
	}
}
