/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:25:28 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:25:29 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	if (!dstsize)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	if (i <= dstsize)
		temp = i;
	else
		temp = dstsize;
	while (i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (temp < dstsize)
		dst[i] = 0;
	return (ft_strlen(src) + temp);
}
