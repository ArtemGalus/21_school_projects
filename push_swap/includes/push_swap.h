/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdenisse <sdenisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:12:32 by sdenisse          #+#    #+#             */
/*   Updated: 2021/08/23 16:30:42 by sdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
typedef struct s_rex
{
	int	nbr;
	int	index;
	int	flag;
}	t_rex;
int		ft_validate(int argc, char **argv, t_list **list);
int		ft_nbrcmp(t_list *list);
void	ft_del(void *p);
int		ft_tanos(t_list **list, void (*func)(void *p));
int		ft_new_elem(t_list **list, int n);
void	ft_error(int err);
int		ft_sorted(t_list *lst);
void	ft_mark(t_list *lst);
void	ft_push_swap(t_list **lst_a, t_list **lst_b);
int		ft_max(t_list *lst, int flag);
int		ft_min(t_list *lst, int flag);
void	ft_push2b(t_list **lst_a, t_list **lst_b, int flag);
void	ft_push2a(t_list **lst_a, t_list **lst_b, int flag, int i);
void	ft_triplesort_b(t_list **lst, int flag);
void	ft_triplesort_a(t_list **lst);
void	ft_smallsort(t_list **lst_a, t_list **lst_b, int size);
void	ft_sort(t_list **lst_a, t_list **lst_b);
void	ft_oper_s(t_list **bag);
void	ft_oper_ss(t_list **bag_a, t_list **bag_b);
void	ft_oper_pa(t_list **lst_a, t_list **lst_b);
void	ft_oper_pb(t_list **lst_a, t_list **lst_b);
void	ft_oper_r(t_list **bag);
void	ft_oper_rr(t_list **bag_a, t_list **bag_b);
void	ft_oper_revr(t_list **bag);
void	ft_oper_rrr(t_list **bag_a, t_list **bag_b);
void	ft_free(char **bag);
void	ft_rotatesorted(t_list **lst);
void	ft_marksorted(t_list **lst_a, t_list **t_lst_b);
int		ft_errid(t_list **list, long n, char **bag);
void	ft_push2bsup(t_list **lst_a, t_list **lst_b, int count);
void	ft_push2bsupr(t_list **lst_a, int min, int i);
void	ft_smallsortsup(t_list **lst_a, t_list **lst_b);
void	ft_smallsortsupr(t_list **lst_a, int flag);
#endif