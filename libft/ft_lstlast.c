#include "libft.h"
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
	}
	return (temp);
}
