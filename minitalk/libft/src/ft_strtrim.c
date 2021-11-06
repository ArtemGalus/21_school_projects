/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:26:04 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:26:04 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(char const c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*bag;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	while (ft_cmp(s1[start], set) && s1[start++])
		;
	while (--end > start && ft_cmp(s1[end], set))
		;
	bag = malloc(sizeof(char) * (end - start + 2));
	if (!bag)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		if (i >= start && i <= end)
			*bag++ = s1[i];
		i++;
	}
	*bag = 0;
	return (bag - end + start - 1);
}

static int	ft_cmp(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
