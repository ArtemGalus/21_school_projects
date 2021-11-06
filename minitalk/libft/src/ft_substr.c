/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:26:07 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:26:07 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*bag;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	if (start > size)
		len = 0;
	if (len > size - start)
		len = size - start;
	bag = malloc(sizeof(char) * (len + 1));
	if (!bag)
		return (NULL);
	while (s[start] && i < len)
	{
		bag[i] = s[start];
		i++;
		start++;
	}
	bag[i] = 0;
	return (bag);
}
