#include "ft_printf.h"

int	ft_x(va_list ap, t_rex bag)
{
	unsigned int	n;
	int				temp;

	n = va_arg(ap, unsigned int);
	temp = ft_putnbr_x(n, bag, 'x');
	return (temp);
}

int	ft_X(va_list ap, t_rex bag)
{
	unsigned int	n;
	int				temp;

	n = va_arg(ap, unsigned int);
	temp = ft_putnbr_x(n, bag, 'X');
	return (temp);
}

int	ft_putnbr_x(unsigned long long int n, t_rex bag, char s)
{
	int	count;

	count = 0;
	ft_print_x(bag, n, &count, s);
	if (bag.minus)
		ft_print_width(bag, s, count, &count);
	return (count);
}
