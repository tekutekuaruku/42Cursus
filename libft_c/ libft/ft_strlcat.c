#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;

	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (size + ft_strlen(src));
	ft_strlcpy(dst + d_len, src, size - d_len);
	return (d_len + ft_strlen(src));
}
