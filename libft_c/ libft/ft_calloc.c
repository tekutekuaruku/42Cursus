#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void *tmp;

	if (!(tmp = (void *)malloc(size * n)))
		return (0);
	ft_bzero(tmp, size * n);
	return (tmp);
}
