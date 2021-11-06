#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_dinosour
{
	int	minus;
	int	flag0;
	int	dot;
	int	pr;
	int	star;
	int	width;
}	t_rex;
int		ft_atoi(const char *str);
void	*ft_bzero(void *b, size_t n);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
int		ft_cmp(char c);
int		ft_pars(const char **format, va_list ap);
int		ft_putnbr_i(long long int n, t_rex bag);
int		ft_putnbr_x(unsigned long long int n, t_rex bag, char s);
void	ft_print_x(t_rex bag, unsigned long long int n, int *count, char s);
int		ft_fun(va_list ap, int i, t_rex bag);
void	ft_print_width(t_rex bag, char s, int len, int *count);
void	ft_print_pr(t_rex bag, int len, int *count);
int		ft_c(va_list ap, t_rex bag);
int		ft_s(va_list ap, t_rex bag);
int		ft_d(va_list ap, t_rex bag);
int		ft_u(va_list ap, t_rex bag);
int		ft_p(va_list ap, t_rex bag);
int		ft_x(va_list ap, t_rex bag);
int		ft_X(va_list ap, t_rex bag);
#endif
