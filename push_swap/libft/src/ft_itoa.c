/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:23:45 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:23:46 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	ft_count(int n);

char	*ft_itoa(int n)
{
	int		k;
	int		size;
	char	*s;

	k = 1;
	if (n < 0)
		k = -1;
	size = ft_count(n);
	if (n < 0)
		size++;
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	s[size--] = 0;
	while (0 <= size)
	{
		s[size--] = k * (n % 10) + '0';
		n = n / 10;
	}
	if (k < 0)
		s[0] = '-';
	return (s);
}

static int	ft_count(int n)
{
	int	x;
	int	size;

	x = 1;
	size = 0;
	while ((n / x / 10) != 0)
	{
		x *= 10;
		size++;
	}
	size++;
	return (size);
}
