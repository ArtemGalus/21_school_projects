/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:12:24 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/25 13:13:45 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate(int argc, char **argv, t_list **list)
{
	int		i;
	long	n;
	char	**bag;
	char	**temp;

	i = 1;
	while (i < argc)
	{
		bag = ft_split(argv[i++], ' ');
		temp = bag;
		if (!bag || !*bag)
		{
			ft_free(temp);
			return (1);
		}
		while (*bag)
		{
			n = ft_errid(list, ft_atoi2(*bag), temp);
			if (n)
				return (n);
			bag++;
		}
		ft_free(temp);
	}
	return (ft_nbrcmp(*list));
}

int	ft_errid(t_list **list, long n, char **bag)
{
	if (n == 3000000000)
	{
		ft_free(bag);
		return (ft_tanos(list, &ft_del) + 1);
	}
	if (n == 3000000001)
	{
		ft_free(bag);
		return (ft_tanos(list, &ft_del) + 2);
	}
	if (n == 3000000002)
	{
		ft_free(bag);
		return (ft_tanos(list, &ft_del) + 3);
	}
	if (ft_new_elem(list, n))
	{
		ft_free(bag);
		return (ft_tanos(list, &ft_del) + 1);
	}
	return (0);
}

void	ft_mark(t_list *lst)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = lst;
	temp2 = lst;
	while (temp1)
	{
		((t_rex *)(temp1->content))->index = 1;
		((t_rex *)(temp1->content))->flag = 0;
		temp2 = lst;
		while (temp2)
		{
			if (((t_rex *)(temp1->content))->nbr >
				((t_rex *)(temp2->content))->nbr)
				((t_rex *)(temp1->content))->index++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

void	ft_push_swap(t_list **lst_a, t_list **lst_b)
{
	ft_mark(*lst_a);
	if (ft_lstsize(*lst_a) == 2)
	{
		ft_oper_s(lst_a);
		write(1, "sa\n", 3);
	}
	if (ft_lstsize(*lst_a) == 3)
		ft_triplesort_a(lst_a);
	if (ft_lstsize(*lst_a) == 4)
		ft_smallsort(lst_a, lst_b, 4);
	if (ft_lstsize(*lst_a) == 5)
		ft_smallsort(lst_a, lst_b, 5);
	if (ft_lstsize(*lst_a) > 5)
		ft_sort(lst_a, lst_b);
}

int	main(int argc, char **argv)
{
	int		err;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = 0;
	lst_b = 0;
	if (argc < 2)
		return (0);
	err = ft_validate(argc, argv, &lst_a);
	if (err)
	{
		ft_error(err);
		return (1);
	}
	if (ft_sorted(lst_a))
		return (0);
	ft_push_swap(&lst_a, &lst_b);
	return (0);
}
