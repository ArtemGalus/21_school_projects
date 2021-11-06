#include "libft.h"
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == *needle)
		{
			temp = (char *)(&haystack[i++]);
			j = 1;
			while (haystack[i] == needle[j] && needle[j] && i < len)
			{
				i++;
				j++;
			}
			if (!needle[j])
				return (temp);
			i = i - j;
		}
		i++;
	}
	return (NULL);
}
