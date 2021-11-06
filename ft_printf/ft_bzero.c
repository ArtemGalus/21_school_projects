#include <stdlib.h>
void	*ft_bzero(void *b, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((char *)b)[i] = 0;
		i++;
	}
	return (b);
}
