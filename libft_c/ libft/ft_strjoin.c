#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	unsigned int	n;
	char			*join;

	n = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc((size + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (*s1)
		join[n++] = *s1++;
	while (*s2)
		join[n++] = *s2++;
	join[n] = '\0';
	return (join);
}
