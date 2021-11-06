#include "ft_printf.h"

int	ft_c(va_list ap, t_rex bag)
{
	char	temp;
	int		count;

	count = 1;
	bag.pr = 1;
	if (bag.width > 1 && !bag.minus)
		ft_print_width(bag, 'c', 1, &count);
	temp = (char)va_arg(ap, int);
	write(1, &temp, 1);
	if (bag.width > 1 && bag.minus)
		ft_print_width(bag, 'c', 1, &count);
	return (count);
}

int	ft_s(va_list ap, t_rex bag)
{
	char	*temp;
	int		i;
	int		len;
	int		count;

	i = 0;
	count = 0;
	temp = va_arg(ap, char *);
	if (!temp)
		temp = "(null)";
	len = ft_strlen(temp);
	if (!bag.dot)
		bag.pr = len;
	if (bag.dot && bag.pr < len)
		len = bag.pr;
	if (!bag.minus)
		ft_print_width(bag, 's', len, &count);
	while (*temp && i < bag.pr && -1 < i++)
		write(1, temp++, 1);
	if (bag.minus)
		ft_print_width(bag, 's', len, &count);
	return (i + count);
}

int	ft_d(va_list ap, t_rex bag)
{
	int	n;
	int	temp;

	n = va_arg(ap, int);
	temp = ft_putnbr_i(n, bag);
	return (temp);
}

int	ft_u(va_list ap, t_rex bag)
{
	unsigned int	n;
	int				temp;

	n = va_arg(ap, unsigned int);
	temp = ft_putnbr_i(n, bag);
	return (temp);
}

int	ft_p(va_list ap, t_rex bag)
{
	unsigned long long int	n;
	int						temp;
	void					*N;

	N = va_arg(ap, void *);
	n = (unsigned long long int)N;
	temp = ft_putnbr_x(n, bag, 'p');
	return (temp);
}
