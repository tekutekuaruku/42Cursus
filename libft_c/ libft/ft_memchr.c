#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)buf;
	while (n > 0)
	{
		if (*tmp == (unsigned char)ch)
			return ((void *)tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
