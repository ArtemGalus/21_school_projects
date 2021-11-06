#include "libft.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*bag;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	bag = malloc(sizeof(char) * (size + 1));
	if (!bag)
		return (NULL);
	i = 0;
	while (*s1)
	{
		bag[i] = *s1;
		s1++;
		i++;
	}
	while (i < size)
	{
		bag[i] = *s2;
		s2++;
		i++;
	}
	bag[i] = 0;
	return (bag);
}
