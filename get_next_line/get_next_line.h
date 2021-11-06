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
