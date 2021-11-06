/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:12:52 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/23 16:18:47 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **bag)
{
	char	**temp1;
	char	*temp2;

	temp1 = bag;
	while (*temp1)
	{
		temp2 = *temp1;
		temp1++;
		free(temp2);
	}
	free(bag);
}

void	ft_del(void *p)
{
	free(p);
	p = 0;
}

int	ft_tanos(t_list **lst, void (*func)(void *p))
{
	ft_lstclear(lst, func);
	return (0);
}

int	ft_new_elem(t_list **list, int n)
{
	t_rex	*new;
	t_list	*new_elem;

	new = malloc(sizeof(t_rex));
	if (!new)
		return (1);
	new->nbr = n;
	new_elem = ft_lstnew(new);
	if (!new_elem)
		return (1);
	ft_lstadd_back(list, new_elem);
	return (0);
}
