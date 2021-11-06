#include "libft.h"
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*bag;
	t_list	*new;

	bag = 0;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&bag, del);
			return (NULL);
		}
		ft_lstadd_back(&bag, new);
		lst = lst->next;
	}
	return (bag);
}
