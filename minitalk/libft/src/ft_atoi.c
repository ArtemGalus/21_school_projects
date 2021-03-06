/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:22:47 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:22:53 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	k;
	int	n;

	k = 1;
	n = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			k = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + k * (*str - '0');
		str++;
	}
	return (n);
}
