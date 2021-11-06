#include "ft_printf.h"

void	ft_pars_dot(const char **format, t_rex *bag, va_list ap);
void	ft_pars_width(const char **format, t_rex *bag, va_list ap);
void	ft_pars_spec(const char **format, t_rex *bag, int *count, va_list ap);

int	ft_pars(const char **format, va_list ap)
{
	int		count;
	t_rex	bag;

	count = 0;
	ft_bzero(&bag, sizeof(t_rex));
	if (**format == '%')
	{
		write(1, "%", 1);
		(*format)++;
		count++;
		return (count);
	}
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			bag.minus = 1;
		if (**format && **format == '0' && !bag.minus)
			bag.flag0 = 1;
		(*format)++;
	}
	ft_pars_width(format, &bag, ap);
	ft_pars_spec(format, &bag, &count, ap);
	return (count);
}

int	ft_fun(va_list ap, int i, t_rex bag)
{
	int	(*func[8])(va_list, t_rex);

	func[0] = ft_c;
	func[1] = ft_s;
	func[2] = ft_p;
	func[3] = ft_d;
	func[4] = ft_d;
	func[5] = ft_u;
	func[6] = ft_x;
	func[7] = ft_X;
	return (func[i](ap, bag));
}

void	ft_pars_dot(const char **format, t_rex *bag, va_list ap)
{
	bag->dot = 1;
	(*format)++;
	bag->pr = ft_atoi(*format);
	if (bag->pr < 0)
	{
		bag->minus = 1;
		bag->dot = 0;
		bag->pr = 0;
		(*format)++;
	}
	if (**format == '0' && bag->pr > 0 && !bag->minus)
		bag->flag0 = 1;
	while (**format >= '0' && **format <= '9')
		(*format)++;
	if (**format && **format == '*')
	{
		bag->pr = va_arg(ap, size_t);
		(*format)++;
		if (bag->pr < 0)
		{
			bag->dot = 0;
			bag->pr = 0;
		}
	}
}

void	ft_pars_width(const char **format, t_rex *bag, va_list ap)
{
	bag->width = ft_atoi(*format);
	if (bag->width < 0)
	{
		bag->minus = 1;
		bag->width = -bag->width;
		(*format)++;
	}
	while (**format >= '0' && **format <= '9')
		(*format)++;
	if (**format && **format == '*')
	{
		bag->width = va_arg(ap, int);
		(*format)++;
		if (bag->width < 0)
		{
			bag->minus = 1;
			bag->width *= -1;
		}
	}
	if (**format && **format == '.')
		ft_pars_dot(format, bag, ap);
}

void	ft_pars_spec(const char **format, t_rex *bag, int *count, va_list ap)
{
	int	i;
	int	n;
	int	len;

	n = 0;
	i = ft_cmp(**format);
	if (i < 0)
	{
		while (**format && **format == '%' && n++ > -1)
			(*format)++;
		len = n;
		*count = *count + n;
		if (!bag->minus)
			ft_print_width(*bag, 's', len, count);
		while (n-- > 0)
			write(1, "%", 1);
		if (bag->minus)
			ft_print_width(*bag, 's', len, count);
		return ;
	}
	if (**format && i >= 0)
	{
		*count = *count + ft_fun(ap, i, *bag);
		(*format)++;
	}
}
