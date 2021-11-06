/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:12:32 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/03 18:32:11 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
typedef struct s_img
{
	void	*img;
	char	*path;
	int		bitness;
	int		line_length;
	int		endian;	
}	t_img;
typedef struct s_gdata
{
	char	***map;
	int		coins;
	int		move_count;
	t_img	wall;
	t_img	ground;
	t_img	exit;
	t_img	coin;
	t_img	player;
	int		pos_x;
	int		pos_y;
	void	*x_id;
	void	*win;
	int		map_width;
	int		map_height;

}	t_gdata;
int		ft_validate(char **argv, char ***map);
int		ft_cpymap(char ***map, int fd, int count);
void	ft_free(char **bag, int i);
int		ft_check_extension(char *str);
int		ft_check_map(int *ar);
int		ft_columns_count(int fd, int **ar);
int		ft_checkLine(int **ar, char *str, int flag);
int		ft_strcmp2(int **ar, char c);
void	ft_checker(int i);
void	get_stat(t_gdata *game);
void	create_bg(t_gdata *g_data);
void	draw_other(t_gdata *g_data);
void	load_textures(t_gdata *game);
void	move_up(t_gdata *g_data);
void	move_down(t_gdata *g_data);
void	move_right(t_gdata *g_data);
void	move_left(t_gdata *g_data);
void	start_game(char ***map, t_gdata *game);
int		key_hook(int key, t_gdata *game);
int		close_window(int key, t_gdata **game);
void	load_wall(t_gdata *game);
void	load_ground(t_gdata *game);
void	load_exit(t_gdata *game);
void	load_player(t_gdata *game);
void	load_coin(t_gdata *game);
void	draw_wall(int i, int j, t_gdata *game);
void	draw_ground(int i, int j, t_gdata *game);
void	draw_exit(int i, int j, t_gdata *game);
void	draw_player(int i, int j, t_gdata *game);
void	draw_coin(int i, int j, t_gdata *game);
#endif