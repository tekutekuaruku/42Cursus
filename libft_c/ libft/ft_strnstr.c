#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	if (len > 0)
	{
		size = ft_strlen(s2);
		while (i < len - (size - 1) && s1[i])
		{
			if (!ft_strncmp(&s1[i], s2, size))
				return ((char *)&s1[i]);
			i++;
		}
	}
	return (NULL);
}
