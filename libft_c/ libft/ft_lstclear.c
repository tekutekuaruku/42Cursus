#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (lst && del)
	{
		tmp = *lst;
		while (tmp)
		{
			tmp_next = tmp->next;
			del(tmp->content);
			free(tmp);
			tmp = tmp_next;
		}
		*lst = NULL;
	}
}
