#include "libft.h"
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	if (!*s1 || !*s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	i = 0;
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s2 && i < n)
	{
		if (i == n - 1)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
