/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsupfunc1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:13:02 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 14:56:24 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list *lst, int flag)
{
	int	max;

	max = 0;
	while (lst)
	{
		if (((t_rex *)(lst->content))->index > max &&
			((t_rex *)(lst->content))->flag == flag)
			max = ((t_rex *)(lst->content))->index;
		lst = lst->next;
	}
	return (max);
}

int	ft_min(t_list *lst, int flag)
{
	int	min;

	min = ((t_rex *)(lst->content))->index;
	while (lst)
	{
		if (((t_rex *)(lst->content))->index < min &&
			((t_rex *)(lst->content))->flag == flag)
			min = ((t_rex *)(lst->content))->index;
		lst = lst->next;
	}
	return (min);
}

void	ft_push2b(t_list **lst_a, t_list **lst_b, int flag)
{
	int	max;
	int	min;
	int	count;
	int	i;

	i = 0;
	max = ft_max(*lst_a, flag);
	min = ft_min(*lst_a, flag);
	count = max - min + 1;
	if (count <= 3 && ((t_rex *)((*lst_a)->content))->flag == flag)
		ft_push2bsup(lst_a, lst_b, count);
	while (count-- > 0 && ((t_rex *)((*lst_a)->content))->flag == flag)
	{
		if (((t_rex *)((*lst_a)->content))->index <= ((max + min) / 2))
			ft_push2bsup(lst_a, lst_b, 1);
		if (((t_rex *)((*lst_a)->content))->index > ((max + min) / 2))
		{
			ft_oper_r(lst_a);
			write(1, "ra\n", 3);
			i++;
		}
	}
	ft_push2bsupr(lst_a, min, i);
}

void	ft_push2bsup(t_list **lst_a, t_list **lst_b, int count)
{
	while (count-- > 0)
	{
		ft_oper_pb(lst_a, lst_b);
		write(1, "pb\n", 3);
	}
}

void	ft_push2bsupr(t_list **lst_a, int min, int i)
{
	while (i-- > 0 && min > 1)
	{
		ft_oper_revr(lst_a);
		write(1, "rra\n", 4);
	}
}
