#include "libft.h"

char	*ft_strrchr(const char *s, int n)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (n == '\0')
		return ((char *)s + i + 1);
	while (i >= 0)
	{
		if (s[i] == n)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
