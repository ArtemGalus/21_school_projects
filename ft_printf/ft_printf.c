#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;
	int		temp;

	size = 0;
	va_start(ap, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			write(1, format++, 1);
			size++;
		}
		if (*format == '%')
		{
			format++;
			temp = ft_pars(&format, ap);
			size = size + temp;
		}
	}
	return (size);
}
