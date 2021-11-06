#include "ft_printf.h"

void	ft_printnbr( long long int n, unsigned int x,
			t_rex bag, int *count);
int		ft_print_startx(t_rex bag, char *str, int i, unsigned long long int n);

int	ft_putnbr_i(long long int n, t_rex bag)
{
	unsigned int	x;
	int				count;
	int				i;

	x = 1;
	i = 1;
	count = 0;
	while (n / x / 10 != 0 && i++ > -1)
		x *= 10;
	if (n < 0)
		bag.width--;
	if (!n && bag.dot && !bag.pr)
		i = 0;
	if (!bag.minus && (!bag.flag0 || bag.dot))
		ft_print_width(bag, 'd', i, &count);
	if (n < 0 && count++ > -1)
		write(1, "-", 1);
	if (!bag.minus && bag.flag0 && !bag.dot)
		ft_print_width(bag, 'd', i, &count);
	ft_print_pr(bag, i, &count);
	ft_printnbr(n, x, bag, &count);
	if (bag.minus)
		ft_print_width(bag, 'd', i, &count);
	return (count + i);
}

void	ft_print_x(t_rex bag, unsigned long long int n, int *count, char s)
{
	char	*str;
	int		i;

	if (s == 'x')
		str = "0123456789abcdefx";
	if (s == 'p')
		str = "0123456789abcdefp";
	if (s == 'X')
		str = "0123456789ABCDEFX";
	(*count)++;
	i = *count;
	if (n / 16 == 0)
	{
		*count = ft_print_startx(bag, str, i, n);
		if (!n && bag.minus)
			ft_print_width(bag, s, *count, count);
		return ;
	}
	ft_print_x(bag, n / 16, count, s);
	write(1, &str[n % 16], 1);
}

void	ft_printnbr(long long int n, unsigned int x,
				 t_rex bag, int *count)
{
	int		k;
	char	temp;

	k = 1;
	if (n < 0)
		k = -1;
	if (!n && bag.dot && !bag.pr)
		return ;
	while (x > 0)
	{
		temp = n / x * k + '0';
		write(1, &temp, 1);
		n = n % x;
		x /= 10;
		count++;
	}
}

int	ft_print_startx(t_rex bag, char *str, int i, unsigned long long int n)
{
	int	count;
	int	x;

	x = 0;
	count = i;
	if (str[16] == 'p')
	{
		count += 2;
		x += 2;
	}
	if (!(n % 16) && bag.dot && !bag.pr)
	{
		count--;
		i = 0;
	}
	if (!bag.minus)
		ft_print_width(bag, str[16], i + x, &count);
	if (str[16] == 'p')
		write(1, "0x", 2);
	ft_print_pr(bag, i, &count);
	if (!(!(n % 16) && bag.dot && !bag.pr))
		write(1, &str[(n % 16)], 1);
	return (count);
}
