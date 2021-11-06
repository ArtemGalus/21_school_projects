/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:55:49 by sdenisse          #+#    #+#             */
/*   Updated: 2021/09/02 17:18:42 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
typedef struct s_rex
{
	int				fd;
	char			s[BUFFER_SIZE];
	int				point;
	int				size;
	struct s_rex	*next;
}	t_rex;
int		get_next_line(int fd, char **line);
int		ft_new_elem2back(t_rex **lst, int fd);
t_rex	*ft_contentcmp(t_rex *lst, int fd);
int		ft_1(char **line, t_rex **buf, int fd, t_rex **lst);
int		ft_in2line(char **line, t_rex *buf, int *i, int *temp);
int		ft_mem(t_rex *buf, int j, int temp, char **line);
int		ft_meteor(t_rex *buf, t_rex **lst);
#endif
