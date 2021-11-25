#include "libft.h"

char	*ft_strchr(const char *s, int n)
{
	while (*s != '\0')
	{
		if (*s == n)
			return ((char *)s);
		s++;
	}
	if (n == '\0')
		return ((char *)s);
	return (NULL);
}
