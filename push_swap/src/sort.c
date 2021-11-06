/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:12:57 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/20 18:44:29 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_triplesort_a(t_list **lst)
{
	int	min;
	int	max;

	min = ft_min(*lst, 0);
	max = ft_max(*lst, 0);
	while (((t_rex *)((*lst)->content))->index != max - 1)
	{
		ft_oper_r(lst);
		write(1, "ra\n", 3);
	}
	if (((t_rex *)((*lst)->next->content))->index == min)
	{
		ft_oper_s(lst);
		write(1, "sa\n", 3);
		return ;
	}
	if (((t_rex *)((*lst)->next->content))->index == max)
	{
		ft_oper_revr(lst);
		write(1, "rra\n", 4);
	}
}

void	ft_smallsort(t_list **lst_a, t_list **lst_b, int size)
{
	t_list	*temp;
	int		i;
	int		min;

	min = 1;
	i = 0;
	temp = *lst_a;
	while (size > 3)
	{
		while (((t_rex *)(temp->content))->index > min && i++ > -1)
			temp = temp->next;
		if (i >= size / 2 + 1)
			while (((t_rex *)((*lst_a)->content))->index > min)
				ft_smallsortsupr(lst_a, 1);
		else
			while (((t_rex *)((*lst_a)->content))->index > min)
				ft_smallsortsupr(lst_a, 0);
		ft_oper_pb(lst_a, lst_b);
		write(1, "pb\n", 3);
		min++;
		size--;
	}
	ft_smallsortsup(lst_a, lst_b);
}

void	ft_smallsortsupr(t_list **lst_a, int flag)
{
	if (flag)
	{
		ft_oper_revr(lst_a);
		write(1, "rra\n", 4);
	}
	else
	{
		ft_oper_r(lst_a);
		write(1, "ra\n", 3);
	}
}

void	ft_smallsortsup(t_list **lst_a, t_list **lst_b)
{
	ft_triplesort_a(lst_a);
	while (*lst_b)
	{
		ft_oper_pa(lst_a, lst_b);
		write(1, "pa\n", 3);
	}
}

void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	int	flag;
	int	y;

	while (!ft_sorted(*lst_a))
	{
		flag = ((t_rex *)((*lst_a)->content))->flag;
		ft_push2b(lst_a, lst_b, flag);
		y = 0;
		while (ft_lstsize(*lst_b) > 3 && y++ > -1)
			ft_push2a(lst_a, lst_b, flag, y);
		ft_triplesort_b(lst_b, flag);
		ft_rotatesorted(lst_a);
		ft_marksorted(lst_a, lst_b);
		ft_rotatesorted(lst_a);
		if (ft_max(*lst_a, 0) == ft_min(*lst_a, 0))
		{
			ft_oper_r(lst_a);
			write(1, "ra\n", 3);
		}
	}
}
