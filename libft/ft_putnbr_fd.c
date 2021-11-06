#include <unistd.h>
void	ft_putnbr_fd(int n, int fd)
{
	int		k;
	int		x;
	char	temp;

	k = 1;
	x = 1;
	while (n / x / 10 != 0)
		x *= 10;
	if (n < 0)
	{
		write(fd, "-", 1);
		k = -1;
	}
	while (x > 0)
	{
		temp = n / x * k + '0';
		write(fd, &temp, 1);
		n = n % x;
		x /= 10;
	}
}
