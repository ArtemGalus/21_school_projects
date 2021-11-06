/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsupfunc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:57:25 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:17:45 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push2asup(t_list **lst_a, t_list **lst_b, int i, int mark)
{
	if (mark)
	{
		((t_rex *)((*lst_b)->content))->flag += i;
		ft_oper_pa(lst_a, lst_b);
		write(1, "pa\n", 3);
	}
	else
	{
		ft_oper_r(lst_b);
		write(1, "rb\n", 3);
	}
}

void	ft_push2a(t_list **lst_a, t_list **lst_b, int flag, int i)
{
	int	max;
	int	min;
	int	count;

	max = ft_max(*lst_b, flag);
	min = ft_min(*lst_b, flag);
	count = max - min + 1;
	while (count-- > 0 && max - min > 3)
	{
		if (((t_rex *)((*lst_b)->content))->index > (max + min) / 2)
			ft_push2asup(lst_a, lst_b, i, 1);
		else
			ft_push2asup(lst_a, lst_b, i, 0);
	}
	while (count-- > 0 && max - min == 3)
	{
		if (((t_rex *)((*lst_b)->content))->index == max)
			ft_push2asup(lst_a, lst_b, i, 1);
		else
			ft_push2asup(lst_a, lst_b, i, 0);
	}
}

void	ft_triplesort_b(t_list **lst, int flag)
{
	int	max;
	int	count;
	int	min;

	if (!*lst)
		return ;
	max = ft_max(*lst, flag);
	min = ft_min(*lst, flag);
	count = max - min + 1;
	while (((t_rex *)((*lst)->content))->index != max - 1 && count > 2)
	{
		ft_oper_r(lst);
		write(1, "rb\n", 3);
	}
	if (count > 1 && ((t_rex *)((*lst)->next->content))->index == max)
	{
		ft_oper_s(lst);
		write(1, "sb\n", 3);
		return ;
	}
	if (count > 2 && ((t_rex *)((*lst)->next->content))->index == min)
	{
		ft_oper_revr(lst);
		write(1, "rrb\n", 4);
	}
}

void	ft_marksorted(t_list **lst_a, t_list **lst_b)
{
	while (*lst_b)
	{
		((t_rex *)((*lst_b)->content))->flag = -1;
		ft_oper_pa(lst_a, lst_b);
		write(1, "pa\n", 3);
	}
}

void	ft_rotatesorted(t_list **lst)
{
	int	max;

	max = ft_max(*lst, -1);
	if (ft_sorted(*lst))
		return ;
	while (((t_rex *)((*lst)->content))->flag == -1)
	{
		if (((t_rex *)((*lst)->content))->index == max)
		{
			ft_oper_r(lst);
			write(1, "ra\n", 3);
			return ;
		}
		ft_oper_r(lst);
		write(1, "ra\n", 3);
	}
}
