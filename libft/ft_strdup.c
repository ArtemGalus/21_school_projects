#include "libft.h"
void	*ft_strdup(const char *s1)
{
	char	*bag;
	size_t	n;

	n = ft_strlen(s1);
	bag = ft_calloc(n + 1, 1);
	if (!bag)
		return (NULL);
	while (*s1)
		*bag++ = *(s1++);
	*bag = 0;
	bag = bag - n;
	return (bag);
}
