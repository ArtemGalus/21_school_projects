/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:25:45 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:25:46 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
