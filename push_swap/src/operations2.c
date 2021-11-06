/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:59:53 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:00:32 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_oper_rr(t_list **bag_a, t_list **bag_b)
{
	ft_oper_r(bag_a);
	ft_oper_r(bag_b);
}

void	ft_oper_revr(t_list **bag)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!bag)
		return ;
	if (!(*bag)->next)
		return ;
	temp1 = *bag;
	while (temp1->next)
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}
	temp2->next = 0;
	temp1->next = *bag;
	*bag = temp1;
}

void	ft_oper_rrr(t_list **bag_a, t_list **bag_b)
{
	ft_oper_revr(bag_a);
	ft_oper_revr(bag_b);
}
