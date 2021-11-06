/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:12:00 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 14:12:08 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbrcmp(t_list *list)
{
	int		temp;
	t_list	*temp2;

	while (list)
	{
		temp2 = list->next;
		temp = ((t_rex *)(list->content))->nbr;
		while (temp2)
		{
			if (((t_rex *)(temp2->content))->nbr == temp)
				return (4);
			temp2 = temp2->next;
		}
		list = list->next;
	}
	return (0);
}

int	ft_sorted(t_list *lst)
{
	int	temp;

	temp = ((t_rex *)(lst->content))->nbr;
	lst = lst->next;
	while (lst)
	{
		if (((t_rex *)(lst->content))->nbr <= temp)
			return (0);
		temp = ((t_rex *)(lst->content))->nbr;
		lst = lst->next;
	}
	return (1);
}

void	ft_error(int err)
{
	if (err == 1)
		write(2, "Error\n", 6);
	if (err == 2)
		write(2, "Error: some nombers are bigger than an integer\n", 44);
	if (err == 3)
		write(2, "Error: some arguments are not integer\n", 38);
	if (err == 4)
		write(2, "Error: some arguments are duplicates\n", 37);
}
