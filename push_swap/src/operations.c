/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:58:08 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/18 15:00:43 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_oper_s(t_list **bag)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*bag)
		return ;
	temp = *bag;
	if (!temp->next)
		return ;
	temp2 = temp->next;
	temp->next = (*bag)->next->next;
	*bag = temp2;
	(*bag)->next = temp;
}

void	ft_oper_ss(t_list **bag_a, t_list **bag_b)
{
	ft_oper_s(bag_a);
	ft_oper_s(bag_b);
}

void	ft_oper_pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!*lst_b)
		return ;
	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	temp->next = 0;
	ft_lstadd_front(lst_a, temp);
}

void	ft_oper_pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!*lst_a)
		return ;
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	temp->next = 0;
	ft_lstadd_front(lst_b, temp);
}

void	ft_oper_r(t_list **bag)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!bag)
		return ;
	if (!(*bag)->next)
		return ;
	temp1 = *bag;
	*bag = (*bag)->next;
	temp1->next = 0;
	temp2 = *bag;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp1;
}
