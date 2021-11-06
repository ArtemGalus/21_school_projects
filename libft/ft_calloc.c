#include "libft.h"
void	*ft_calloc(size_t count, size_t size)
{
	void	*bag;

	bag = malloc(size * count);
	if (!bag)
		return (bag);
	ft_bzero(bag, count * size);
	return (bag);
}
