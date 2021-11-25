#include "libft.h"

void	*ft_memset(void *buf, int ch, unsigned int n)
{
	unsigned int	m;
	unsigned char	*tmp;

	m = 0;
	tmp = (unsigned char *)buf;
	while (m < n)
	{
		tmp[m] = (unsigned char)ch;
		m++;
	}
	return (buf);
}
