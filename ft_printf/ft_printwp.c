#include "ft_printf.h"

void	ft_charcmp(t_rex *bag, char s, int len);

int	ft_cmp(char c)
{
	int		i;
	char	*s;

	s = "cspdiuxX";
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_print_width(t_rex bag, char s, int len, int *count)
{
	char	c;

	c = ' ';
	if (s == 's' || s == 'c')
	{
		bag.dot = 0;
		bag.pr = len;
	}
	ft_charcmp(&bag, s, len);
	if (bag.flag0 && !bag.minus && !bag.dot)
		c = '0';
	while (bag.width-- > bag.pr)
	{
		write (1, &c, 1);
		(*count)++;
	}
}

void	ft_print_pr(t_rex bag, int len, int *count)
{
	while (bag.pr-- > len)
	{
		write (1, "0", 1);
		(*count)++;
	}
}

void	ft_charcmp(t_rex *bag, char s, int len)
{
	if (s != 's' && s != 'c')
	{
		if (s == 'p')
			bag->pr += 2;
		if (bag->pr < len)
			bag->pr = len;
	}
}
