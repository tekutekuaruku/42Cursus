#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del)
	{
		(*del)(lst->content);
		free(lst);
	}
}
