/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:25:12 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:25:13 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static size_t	ft_size(char const *s, char c);
static int		ft_create(char const *s, char c, char **bag);
static int		arrdeath(char **bag, size_t x);

char	**ft_split(char const *s, char c)
{
	char	**bag;
	size_t	i;
	size_t	j;

	bag = malloc(sizeof(char *) * (ft_size(s, c) + 1));
	if (!bag)
		return (NULL);
	i = 0;
	if (!ft_create(s, c, bag))
		return (NULL);
	while (bag[i])
	{
		while (*s == c && *s)
			s++;
		j = 0;
		while (*s != c && *s)
		{
			bag[i][j] = *s;
			j++;
			s++;
		}
		bag[i][j] = 0;
		i++;
	}
	return (bag);
}

static size_t	ft_size(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == c)
			size++;
		if (s[i])
			i++;
	}
	if (s[i - 1] != c)
		size++;
	return (size);
}

static int	ft_create(char const *s, char c, char **bag)
{
	size_t	i;
	size_t	size;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		size = 0;
		while (*s != c && *s)
		{
			size++;
			s++;
		}
		if (size)
		{
			bag[i++] = malloc(sizeof(char) * (size + 1));
			if (!bag[i - 1])
				return (arrdeath(bag, i - 1));
		}
		if (*s)
			s++;
	}
	bag[i] = NULL;
	return (1);
}

static int	arrdeath(char **bag, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
		free(bag[i++]);
	free(bag);
	return (0);
}
