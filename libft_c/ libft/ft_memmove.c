#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d_copy;
	unsigned char	*s_copy;

	d_copy = (unsigned char *)dst;
	s_copy = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (d_copy < s_copy)
	{
		while (n--)
			*d_copy++ = *s_copy++;
	}
	else
	{
		d_copy += n - 1;
		s_copy += n - 1;
		while (n > 0)
		{
			*d_copy-- = *s_copy--;
			n--;
		}
	}
	return (dst);
}
