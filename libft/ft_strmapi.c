#include "libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*bag;

	len = ft_strlen(s);
	bag = malloc(sizeof(char) * (len + 1));
	if (!bag)
		return (NULL);
	i = 0;
	while (i < len)
	{
		bag[i] = f(i, s[i]);
		i++;
	}
	bag[i] = 0;
	return (bag);
}
